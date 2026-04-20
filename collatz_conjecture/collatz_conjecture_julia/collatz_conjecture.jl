#=
Program: Collatz Conjecture Generator
Description: Takes a positive integer and applies the 3n + 1 algorithm 
             until the sequence reaches 1, counting the steps taken.
=#

function collatz_sequence(n::Int)
    sequence = [n] 
    while n > 1
       if n % 2 == 0
          # Update n by dividing it by 2
          n = div(n, 2) 
       else 
          n = 3n + 1
       end
       push!(sequence, n)
    end
    return sequence # Return the actual list of numbers
end

print("Enter a starting number for the Collatz sequence: ")

user_input = readline()
start_node = parse(Int, user_input)

result = collatz_sequence(start_node)
println("\nSequence: ", result)