#Jeorge D. Anderson II
#The Mandelbrot Set in Python

import numpy as np


def mandelbrot(X, Y, max_iterations=1000, verbose=True):
    
    # init the output array
    out_arr = np.zeros((len(Y), len(X)))

    # Iterate of the y coordinates
    for i, y in enumerate(Y):
        for j, x in enumerate(X):
            n = 0
            c = x + 1j*y
            z = c
            while (n < max_iterations) and (abs(z) <= 2):
                z = z*z + c
                n += 1
            out_arr[i, j] = n

    return out_arr