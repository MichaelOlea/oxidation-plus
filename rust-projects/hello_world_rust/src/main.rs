use std::io;
fn main() {
    println!("Hello world!");

    println!("Press Enter to close");
    io::stdin().read_line(&mut String::new()).unwrap();

}