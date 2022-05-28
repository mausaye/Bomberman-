//
// Created by Robert Hammond on 5/11/22.
//

#ifndef BOMBERMAN2_0_THREADSAFEQUEUE_HPP
#define BOMBERMAN2_0_THREADSAFEQUEUE_HPP
#include <queue>
#include <condition_variable>
#include <mutex>

template <class T>
class ThreadSafeQueue {
public:
    ThreadSafeQueue() : q(), c(), m() {}

    void push(T el) {
        std::lock_guard<std::mutex> lock(m);
        q.push(el);
        c.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(m);
        while (q.empty()) {
            c.wait(lock);
        }
        T el = q.front();
        q.pop();
        return el;
    }

    bool empty() {
        return q.empty();
    }

    size_t size() {
        return q.size();
    }

private:
    std::queue<T> q;
    std::condition_variable c;
    mutable std::mutex m;
};


#endif //BOMBERMAN2_0_THREADSAFEQUEUE_HPP
