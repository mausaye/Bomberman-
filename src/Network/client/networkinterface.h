#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <queue>
#include "../../Utils/ThreadSafeQueue.hpp"
#include "../Messages/Message.h"

#ifndef BOMBERMAN2_0_NETWORKINTERFACE_H
#define BOMBERMAN2_0_NETWORKINTERFACE_H
//TODO: Add header, make some stuff effectively hidden.
namespace ClientSideNetworking {
    //buffer shared between networking thread and main thread
    ThreadSafeQueue<std::string> unread_messages;

    //port of particular client to send and receive stuff.
    const int MY_PORT = 7258;

    //server info - self-explanatory.
    const int SERVER_PORT = 7257;
    const char* SERVER_IP = "127.0.0.1";
    auto dest = boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(SERVER_IP), SERVER_PORT);

    //thread that handles the constant receiving.
    std::thread networking_thread;


    //service for both sending and receiving sockets
    boost::asio::io_service io_service;

    //structure for outgoing messages
    boost::asio::ip::udp::socket send_socket(io_service);

    //structure for incoming messages.
    struct Receiver {
    public:
        explicit Receiver(boost::asio::io_service& io_service)
                : recv_socket(io_service, boost::asio::ip::udp::endpoint(
                boost::asio::ip::udp::v4(), MY_PORT)
        )
        {
            startReceive();
        }

    private:
        void startReceive() {
            recv_socket.async_receive_from(
                    boost::asio::buffer(buffer), server_endpoint,
                    boost::bind(&Receiver::handleReceive, this,
                                boost::asio::placeholders::error,
                                boost::asio::placeholders::bytes_transferred));
        }

        void handleReceive(const boost::system::error_code& error, std::size_t bytes_transferred) {
            if (!error || error == boost::asio::error::message_size) {

                addToSharedBuffer(bytes_transferred);


                reset();
            }

        }

        void addToSharedBuffer(std::size_t bytes_transferred) {
            std::string s;
            for (int i = 0; i < bytes_transferred; i++) {
                s.push_back(buffer[i]);
            }
            unread_messages.push(s);
        }


        void reset() {
            startReceive();
        }

        boost::asio::ip::udp::socket recv_socket;
        boost::asio::ip::udp::endpoint server_endpoint;
        std::array<char, 1024> buffer{};
    };

    //Message decode(std::string encoded_message) {

    //}

    //send to server
    void send(int id, const char* msg) {
        size_t len = strlen(msg);
        send_socket.open(boost::asio::ip::udp::v4());
        send_socket.send_to(boost::asio::buffer(msg, len), dest);
    }

    void receive() {
        try {
            Receiver server{io_service};
            io_service.run();
        } catch (const std::exception& ex) {
            std::cerr << ex.what() << std::endl;
        }
    }

    void init() {
        networking_thread = std::thread(receive);
    }

    void stop() {
        io_service.stop();
        networking_thread.join();
    }
}

#endif //BOMBERMAN2_0_NETWORKINTERFACE_H
