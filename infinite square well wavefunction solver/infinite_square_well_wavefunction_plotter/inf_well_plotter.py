import matplotlib.pyplot as plt
import pandas as pd
from itertools import islice
import io

file_path = r'C:\Users\micha\Documents\projects\exploring-rust-cpp\non-rust-or-cpp\infinite square well wavefunction plotter\wave.csv'
search_word = "State n = "
indices = []
start = 0

with open(file_path, 'r') as file:

    # get index for chunk slices
    for line_number, line in enumerate(file, 1):
        if search_word in line:
            indices.append(line_number)

    # Slice
    for end in range(len(indices)):
        chunk_size = end - indices[end]
        print(chunk_size)
