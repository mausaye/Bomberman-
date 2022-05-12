#ifndef BOMBERMAN2_0_MESSAGE_H
#define BOMBERMAN2_0_MESSAGE_H
#include <string>

/*
 * How this will work
 *      - To send(Messgage, return void) to server/client, create message object, call relevant send function
 *      - Send function is responsible for calling get_string_representation and getting the length
 *        so byte size is calculated and sent
 *      - Receive(void, ret Message) function on other end is responsible for getting the string rep and reconstructing
 *        it as a message (prolly just via a constructor that just takes strings). From there,
 *        message can be analyzed.
 */


class Message {
public:
    virtual ~Message() {};
    std::string get_string_representation();
    
private:
    std::string string_representation;
};


#endif //BOMBERMAN2_0_MESSAGE_H
