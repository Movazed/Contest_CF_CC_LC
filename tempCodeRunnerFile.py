import sys
from collections import defaultdict
import threading

def fetch_input():
    """Reads input values and initializes data structures."""
    # Read the size of the sequence
    sequence_size = int(sys.stdin.readline())
    
    # Read the sequence of integers
    sequence = list(map(int, sys.stdin.readline().strip().split()))
    
    # Initialize a dictionary to track high values, starting with {0: 1}
    high_tracker = defaultdict(int, {0: 1})
    
    # Initialize a dictionary to track low values
    low_tracker = defaultdict(int)
    
    return sequence_size, sequence, high_tracker, low_tracker

def process_sequences():
    """Processes sequences and computes results."""
    MOD = 998244353
    test_cases = int(sys.stdin.readline())
    
    while test_cases > 0:
        # Fetch input values
        size, numbers, high_dict, low_dict = fetch_input()
        
        # Iterate through the sequence
        for idx in range(size):
            current_value = numbers[idx]
            
            # Calculate ways to form high values
            high_ways = (high_dict[current_value] + low_dict[current_value]) % MOD
            
            # Update current high dictionary
            current_high = defaultdict(int, {current_value: high_ways}) if high_ways > 0 else defaultdict(int)
            
            # Update current low dictionary
            current_low = defaultdict(int)
            for key in high_dict:
                current_low[key + 1] = (current_low[key + 1] + high_dict[key]) % MOD
            
            # Update previous dictionaries for the next iteration
            high_dict = current_high
            low_dict = current_low
        
        # Compute the total number of valid sequences
        total = 0
        for key in high_dict:
            total = (total + high_dict[key]) % MOD
        for key in low_dict:
            total = (total + low_dict[key]) % MOD
        
        # Print the result for the current test case
        print(total)
        test_cases -= 1

def main():
    """Main function to execute the program."""
    # Create a thread to run the sequence processing function
    thread = threading.Thread(target=process_sequences)
    thread.start()
    thread.join()

if __name__ == "__main__":
    main()