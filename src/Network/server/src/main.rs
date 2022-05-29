use std::net::UdpSocket;
use std::thread;

fn main() -> std::io::Result<()> {
    {
        let mut socket = UdpSocket::bind("127.0.0.1:7257")?;
        let mut buf = [0; 4096];
        loop {
            let sock = socket.try_clone()?;
            match socket.recv_from(&mut buf) {
                Ok((amt, src)) => {
                    thread::spawn(move || {
                        println!("Handling connection from {}", &src);
                        let buf = &mut buf[..amt];
                        for (x )  in buf {
                            print!("{}", *x as char);
                        }
                        println!();
                    });
                },
                Err(err) => {
                    eprintln!("Err: {}", err);
                }
            }
        }
    }
}
