## The Collatz Conjecture

The Collatz conjecture is one of the most famous unsolved problems in mathematics. It proposes that a specific sequence will always reach 1, regardless of which positive integer you start with. The rules are simple: if the current number is even, divide it by 2; if it is odd, triple it and add 1.

Despite its simplicity, no one has been able to prove that every starting value eventually falls into the $4 \rightarrow 2 \rightarrow 1$ loop.



### Introduction

Take any positive whole number, which we will denote as $n$. If the number is even, divide it by $2$. If the number is odd, multiply it by $3$ and add $1$.

$$
f(n) =
\begin{cases} 
\frac{n}{2} & \text{if } n \text{ is even} \\
3n + 1 & \text{if } n \text{ is odd}
\end{cases}
$$

**Examples:**
* **6** is even: $6 \div 2 \rightarrow 3$
* **3** is odd: $(3 \cdot 3) + 1 \rightarrow 10$
* **10** is even: $10 \div 2 \rightarrow 5$
* **5** is odd: $(3 \cdot 5) + 1 \rightarrow 16$
* **16** is even: $16 \div 2 \rightarrow 8 \dots$ eventually reaching **1**.

Starting with a relatively large number like **13**, we can create a chain of numbers:  
$13 \rightarrow 40 \rightarrow 20 \rightarrow 10 \rightarrow 5 \rightarrow 16 \rightarrow 8 \rightarrow 4 \rightarrow 2 \rightarrow 1$. 

Something **interesting** happens when we reach the number **4**: since 4 is even, dividing by 2 gives us 2; since 2 is even, dividing by 2 gives us 1. Because 1 is odd, we multiply by 3 and add 1, reaching 4 again. We then end up at 1 once more, creating an infinite loop.

The Collatz conjecture posits that every positive integer will eventually reach 1 and fall into this loop. Because there are infinitely many integers, it is impossible to prove this simply by checking every number. However, that hasn't stopped mathematicians and computer scientists from using brute force to check as many numbers as possible.

### Implementation

Our goal is to create an algorithm that takes any integer input from the user, processes it through specific logic, and terminates at **1**. This is much simpler to describe than it is to implement.

**Algorithm Basic Logic:**
* **Input:** Ask the user for an integer.
* **Validation:** Verify that the input is a valid positive integer.
* **Main Loop:**
    * If the number is **even**, divide it by 2.
    * If the number is **odd**, multiply it by 3 and add 1.
* **Termination:** Repeat this process until the sequence reaches 1.

**Source Code Links:**
* [Rust Source Code](rust-projects/collatz_conjecture_rust/src/main.rs)
* [C++ Source Code](cpp-projects/collatz_conjecture_cpp/collatz_conjecture.cpp)
* [Julia Source Code](collatz_conjecture/collatz_conjecture_julia/collatz_conjecture.jlz)

---

## Estimating the value of $\pi$ with the Monte Carlo Method

Ever wonder how you could calculate one of the universe's most famous mathematical constants just by throwing a million random darts at a board? That is exactly what this project demonstrates. By leveraging the power of probability and randomness, we use the Monte Carlo method to accurately estimate the value of $\pi$.

### Introduction

Imagine a circle perfectly inscribed inside a square. 
* The area of the circle is given by: $A_c = \pi r^2$
* The area of the square is given by: $A_s = 4r^2$

We can express the relationship between these two shapes as the ratio of the area of the circle to the area of the square:
$
\frac{A_c}{A_s} = \frac{\pi r^2}{4 r^2} = \frac{\pi}{4}
$ 

To isolate $\pi$, we use basic algebra to multiply both sides of the equation by 4. This gives us our theoretical formula:
$
\pi = 4 \times \frac{A_c}{A_s}
$

**Translating Theory to Code:**
If we randomly generate points inside the square, the probability of a point falling inside the circle is directly proportional to the ratio of their areas. Therefore, we can replace the area ratio ($\frac{A_c}{A_s}$) with the ratio of our randomly generated points. 

This gives us our final estimation formula:
$
\pi \approx 4 \times \frac{\text{Points in Circle}}{\text{Total Points}}
$

### Implementation

Without getting bogged down in hardcore mathematics, the implementation relies on straightforward geometry. We use a circle with a radius of 1 centered at the origin $(0,0)$. A randomly generated point $(x, y)$ falls inside this circle if $x^2 + y^2 \le 1$.

**Algorithm Basic Logic:**
* **Function**:
    * **Loop**:
        * Generate a random coordinate $(x, y)$ on the plane strictly inside the unit square.
        * Calculate if $x^2 + y^2 \le 1$. If true, keep count of the point as being inside the circle. 
    * **Termination**: Once the loop has run 10,000,000 times, terminate and return the estimate of $\pi$ using the point-ratio formula above.

**Source Code Links:**
* [C++ Source Code](monte_carlo_estimation_of_pi/est_of_pi_cpp/est_of_pi.cpp)
* [Julia Source Code](monte_carlo_estimation_of_pi/est_of_pi_julia/est_of_pi.jl)
* [Rust Source Code](monte_carlo_estimation_of_pi/est_of_pi_rust/src/main.rs)