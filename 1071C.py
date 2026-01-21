import random

def generate_test_file(filename="input.txt", t=50):
    with open(filename, 'w') as f:
        # Write number of test cases
        f.write(f"{t}\n")
        
        for i in range(t):
            # Scale n: mix of small edge cases and larger stress tests
            if i < 10:
                n = 2  # Hardest edge case
            else:
                n = random.randint(2, 1000)
            
            # Scenario logic
            prob = random.random()
            if prob < 0.3:
                # Case A focus: small elements, small gaps
                start = random.randint(1, 100)
                a = random.sample(range(start, start + n * 5), n)
            elif prob < 0.6:
                # Case B focus: Huge gap between a[0] and a[1]
                a0 = random.randint(1, 1000)
                a1 = a0 + random.randint(10**7, 10**8) # Massive gap
                a = [a0, a1]
                if n > 2:
                    remaining = random.sample(range(a1 + 1, 10**9), n - 2)
                    a.extend(remaining)
            else:
                # Random Large Numbers
                a = random.sample(range(1, 10**9), n)
            
            # Shuffle to ensure the array isn't always pre-sorted
            random.shuffle(a)
            
            # Write n and the array to the file
            f.write(f"{n}\n")
            f.write(" ".join(map(str, a)) + "\n")

    print(f"Successfully generated {t} test cases in '{filename}'")

if __name__ == "__main__":
    generate_test_file()