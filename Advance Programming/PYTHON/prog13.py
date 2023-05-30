import time

def geometric_progression(a, q):
    start_time = time.time()  # Start time for total time calculation
    term_time = 0  # Time within the loop

    term = a
    while term <= 100000:
        yield term
        term_time += time.time() - start_time
        term *= q

    total_time = time.time() - start_time  # Total time taken

    print(f"Total time: {total_time} seconds")
    print(f"Time within loop: {term_time} seconds")

# Example usage
a = 1
q = 2
progression_generator = geometric_progression(a, q)

for term in progression_generator:
    print(term)
