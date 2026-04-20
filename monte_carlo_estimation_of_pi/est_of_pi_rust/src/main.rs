/*
Program:     Monte Carlo Estimation of Pi
Description: Simulates throwing random points into a 2x2 square containing 
             a unit circle. The ratio of points landing inside the circle 
             to the total points sampled is used to approximate the value of PI.
*/

// Importing the necessary traits and types from the rand crate.
// 'Uniform' allows for equal probability across the range.
use rand::distr::{Distribution, Uniform};

fn main() {
    // Define a uniform distribution range between -1.0 and 1.0.
    // 'unwrap()' is used here because the range is guaranteed valid.
    let range = Uniform::new(-1.0f64, 1.0).unwrap();
    
    // Initialize the local random number generator.
    let mut rng = rand::rng();

    let total = 10_000_000;
    let mut in_circle = 0;

    // Use a range loop. '0..total' is exclusive of the upper bound.
    for _ in 0..total {
        // Sample two independent points (x and y) from the uniform distribution.
        let a = range.sample(&mut rng);
        let b = range.sample(&mut rng);

        // Standard distance formula: if x² + y² <= 1.0, the point is inside the circle.
        if a * a + b * b <= 1.0 {
            in_circle += 1;
        }
    }

    // Rust requires explicit type casting (as f64) for arithmetic operations 
    // involving different types (e.g., dividing an integer by an integer 
    // to get a float).
    println!(
        "pi is approx {}", 4.0 * (in_circle as f64) / (total as f64)
    );
}