use std::collections::HashMap;

#[derive(Hash, Eq, PartialEq, Debug)]
pub struct Client {
    messages_sent: Vec<String>,
}


pub fn handle_message(id: i32, message: String) {
    println!("{}", message);

}


