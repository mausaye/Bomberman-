#include <boost/asio.hpp>
#ifndef BOMBERMAN2_0_NETWORKINTERFACE_H
#define BOMBERMAN2_0_NETWORKINTERFACE_H

#endif //BOMBERMAN2_0_NETWORKINTERFACE_H
namespace network {
    const int PORT = 7257;
    const char* IP = "127.0.0.1";
    boost::asio::io_service io_service;
    auto dest = boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(IP), PORT);
    boost::asio::ip::udp::socket socket(io_service);

    //send to server
    void send(int id, const char* msg) {
        size_t len = strlen(msg);
        socket.open(boost::asio::ip::udp::v4());
        socket.send_to(boost::asio::buffer(msg, len), dest);
    }

    //get msg from server
    void receive();

    void init() {

    }

}
