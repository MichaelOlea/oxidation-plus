/*
Program:     Monte Carlo Estimation of Pi
Description: Simulates throwing random points into a 2x2 square containing 
             a unit circle. The ratio of points landing inside the circle 
             to the total points sampled is used to approximate the value of PI.
*/

#include <iostream>
#include <random>

int main() {
    // Total number of random points to generate. 
    // Higher values increase accuracy but take more processing time.
    constexpr int TOTAL_ITERATIONS = 10'000'000; 
    
    // Counter for points that fall within the unit circle boundaries.
    int circle_points = 0; 

    // Initialize Mersenne Twister random number generator with a hardware seed.
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Define the range for both X and Y coordinates to cover a 2x2 square 
    // centered at the origin (from -1 to 1).
    std::uniform_real_distribution<double> dist(-1.0, 1.0);

    for (int i = 0; i < TOTAL_ITERATIONS; ++i) {
        // Generate random coordinates within the square.
        double rand_x = dist(gen);
        double rand_y = dist(gen);

        // Check if the point lies inside the unit circle using the Pythagorean theorem:
        // x^2 + y^2 <= r^2 (where radius r = 1).
        if (rand_x * rand_x + rand_y * rand_y <= 1.0) {
            circle_points++;
        }
    }

    /* The Area of the square is 2 * 2 = 4.
       The Area of the circle is PI * r^2 = PI * 1^2 = PI.
       The ratio (Circle Area / Square Area) is PI / 4.
       Therefore, PI = 4 * (points_in_circle / total_points).
    */
    double pi = 4.0 * static_cast<double>(circle_points) / TOTAL_ITERATIONS;
    
    std::cout << "Estimated value of PI after " << TOTAL_ITERATIONS 
              << " iterations: " << pi << std::endl;

    return 0;
}