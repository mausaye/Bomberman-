pub mod MessageHandler;

use MessageHandler::Client;
use MessageHandler::handle_message;
use std::collections::HashMap;
use std::net::UdpSocket;
use std::thread;


fn main() -> std::io::Result<()> {
    let mut clients: HashMap<i64, Client> = HashMap::new();

    {
        let mut socket = UdpSocket::bind("127.0.0.1:7257")?;
        let mut buf = [0; 4096];
        loop {
            let sock = socket.try_clone()?;
            match socket.recv_from(&mut buf) {
                Ok((amt, src)) => {
                    thread::spawn(move || {
                        println!("Handling connection from {}", &src);
                        let mut msg = String::new();
                        let buf = &mut buf[..amt];
                        for (x)  in buf {
                            msg.push(*x as char);
                        }
                        handle_message(0, msg);
                    });
                },
                Err(err) => {
                    eprintln!("Err: {}", err);
                }
            }
        }
    }
}
