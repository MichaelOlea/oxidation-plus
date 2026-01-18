use std::io;

fn main() {
    // Initialize variables to track the current value and the number of steps taken
    let mut crrnt_num: i64 = 0;
    let mut count: i64 = 0;
    let mut input = String::new();

    println!("Enter a starting number: ");

    // Read user input from the standard input stream
    io::stdin()
        .read_line(&mut input)
        .expect("An error has occurred");

    // Convert the input string into a 64-bit integer
    crrnt_num = input.trim().parse().expect("Please type a number");

    // Validate that the number is a positive integer as required by the conjecture
    if crrnt_num <= 0 {
        println!("Enter a positive integer");
        return;
    }

    // Continue the loop until the sequence reaches 1
    while crrnt_num != 1 {
        print!("{} ", crrnt_num);
        count += 1;

        // Collatz Logic: 
        // If the number is even, divide by 2.
        // If the number is odd, multiply by 3 and add 1.
        if crrnt_num % 2 == 0 {
            crrnt_num = crrnt_num / 2;
        } else {
            crrnt_num = crrnt_num * 3 + 1;
        }
    }

    // Print the final 1 in the sequence and the total step count
    println!("1");
    println!("Total Steps: {}", count)
}