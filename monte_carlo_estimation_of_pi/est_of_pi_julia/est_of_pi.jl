#=
Program:     Monte Carlo Estimation of Pi
Description: Simulates throwing random points into a 2x2 square containing 
             a unit circle. The ratio of points landing inside the circle 
             to the total points sampled is used to approximate the value of PI.
=#

function est_pi(n::Int)
    
    points_inside_circle = 0

    for _ in 1:n

        x, y = rand(-1.0:1e-16:1.0), rand(-1.0:1e-16:1.0)

        if x^2 + y^2 <= 1.0
            points_inside_circle += 1
        end
    end

    return (points_inside_circle * 4) / n
end

n_points = 10_000_000
result = est_pi(n_points)

println("Estimation of Pi: ", result)
