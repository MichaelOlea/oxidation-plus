#include <iostream>

/**
 * Program: Collatz Conjecture Generator
 * Description: Takes a positive integer and applies the 3n + 1 algorithm 
 * until the sequence reaches 1, counting the steps taken.
 */

int main() {
    // Use long long to prevent overflow, as Collatz sequences can 
    // reach very high values even with small starting inputs.
    long long crrnt_num = 0;
    int count = 0;

    // Prompt for user input
    std::cout << "Enter a starting number: ";
    std::cin >> crrnt_num;

    // Input Validation: The conjecture only applies to positive integers (n > 0)
    if (crrnt_num <= 0) {
        std::cerr << "Error: Please enter a positive integer!" << std::endl;
        return 1;
    }

    // Process the sequence until it hits the 4-2-1 loop base case
    while (crrnt_num != 1) {
        std::cout << crrnt_num << " "; 
        count++;

        // Algorithm Logic:
        // If the number is even, divide by 2.
        // If the number is odd, multiply by 3 and add 1.
        if (crrnt_num % 2 == 0) {
            crrnt_num /= 2; 
        } else {
            crrnt_num = (crrnt_num * 3) + 1; 
        }
    }

    // Display final results
    std::cout << "1" << std::endl;
    std::cout << "Total Steps: " << count << std::endl;

    return 0;
}