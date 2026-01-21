#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stdexcept>
#include <cctype>

/**
 * @brief Enables fast I/O operations for competitive programming.
 */
void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

// Global structures to store 7-segment patterns
std::map<char, std::vector<std::string>> patterns;
std::map<std::vector<std::string>, char> reverse_patterns;
std::vector<char> all_chars;

/**
 * @brief Initializes maps with standard 7-segment display patterns for digits and operators.
 * * This function populates the global `patterns`, `reverse_patterns`, and `all_chars`
 * data structures, which are essential for parsing the display and constructing equations.
 */
void setup_patterns() {
    patterns['0'] = {" _ ", "| |", "|_|"};
    patterns['1'] = {"   ", "  |", "  |"};
    patterns['2'] = {" _ ", " _|", "|_ "};
    patterns['3'] = {" _ ", " _|", " _|"};
    patterns['4'] = {"   ", "|_|", "  |"};
    patterns['5'] = {" _ ", "|_ ", " _|"};
    patterns['6'] = {" _ ", "|_ ", "|_|"};
    patterns['7'] = {" _ ", "  |", "  |"};
    patterns['8'] = {" _ ", "|_|", "|_|"};
    patterns['9'] = {" _ ", "|_|", " _|"};
    patterns['+'] = {"   ", " | ", "_|_"};
    patterns['-'] = {"   ", "___", "   "};
    // Representations for '*' and '%' are based on plausible segment constructions.
    patterns['*'] = {"_|_", " | ", "_|_"}; 
    patterns['%'] = {"_ _", "_|_", " _ "};
    patterns['='] = {"   ", "___", "___"};

    for (const auto& pair : patterns) {
        all_chars.push_back(pair.first);
        reverse_patterns[pair.second] = pair.first;
    }
}

/**
 * @brief Counts the number of differing segments (on vs. off) between two 3x3 patterns.
 * @param p1 The first pattern.
 * @param p2 The second pattern.
 * @return The number of segments that differ.
 */
int count_segment_diff(const std::vector<std::string>& p1, const std::vector<std::string>& p2) {
    int diff = 0;
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            bool seg1 = (p1[r][c] != ' ');
            bool seg2 = (p2[r][c] != ' ');
            if (seg1 != seg2) {
                diff++;
            }
        }
    }
    return diff;
}

/**
 * @brief Evaluates a mathematical expression string sequentially from left to right.
 * @param lhs The left-hand side of the equation as a string.
 * @return The result of the calculation as a long long. Returns large negative values for errors.
 */
long long evaluate_lhs(const std::string& lhs) {
    if (lhs.empty()) return 0;
    
    std::vector<long long> numbers;
    std::vector<char> ops;
    std::string current_num_str;

    for (char c : lhs) {
        if (std::isdigit(c)) {
            current_num_str += c;
        } else {
            if (!current_num_str.empty()) {
                numbers.push_back(std::stoll(current_num_str));
                current_num_str = "";
            }
            ops.push_back(c);
        }
    }
    if (!current_num_str.empty()) {
        numbers.push_back(std::stoll(current_num_str));
    }

    if (numbers.empty()) return 0;

    long long result = numbers[0];
    for (size_t i = 0; i < ops.size(); ++i) {
        if (i + 1 >= numbers.size()) return -2e18; // Invalid expression (e.g., "5+")
        
        long long next_num = numbers[i + 1];
        switch (ops[i]) {
            case '+': result += next_num; break;
            case '-': result -= next_num; break;
            case '*': result *= next_num; break;
            case '%': 
                if (next_num != 0) result %= next_num;
                else return -1e18; // Error for division by zero
                break;
        }
    }
    return result;
}

/**
 * @brief Main logic to read input, find the faulty segment, and print the result.
 */
void solve() {
    int n;
    std::cin >> n;
    std::cin.ignore(); 

    std::vector<std::string> display_lines(3);
    for (int i = 0; i < 3; ++i) {
        std::getline(std::cin, display_lines[i]);
    }

    // Parse the input display into N 3x3 character patterns
    std::vector<std::vector<std::string>> displayed_patterns(n, std::vector<std::string>(3));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i * 4 + 3 <= display_lines[j].length()) {
                displayed_patterns[i][j] = display_lines[j].substr(i * 4, 3);
            } else if (i * 4 < display_lines[j].length()) {
                 displayed_patterns[i][j] = display_lines[j].substr(i * 4);
                 while(displayed_patterns[i][j].length() < 3) displayed_patterns[i][j] += ' ';
            } else {
                displayed_patterns[i][j] = "   ";
            }
        }
    }

    // Find the position of '=', which is guaranteed to be correct
    int eq_pos = -1;
    for (int i = 0; i < n; ++i) {
        if (displayed_patterns[i] == patterns.at('=')) {
            eq_pos = i;
            break;
        }
    }

    // Decode the RHS, which is also guaranteed to be correct
    std::string rhs_str;
    for (int i = eq_pos + 1; i < n; ++i) {
        if (reverse_patterns.count(displayed_patterns[i])) {
            rhs_str += reverse_patterns.at(displayed_patterns[i]);
        }
    }
    long long rhs_val = std::stoll(rhs_str);

    // Iterate through each LHS character, assuming it's the faulty one
    for (int faulty_pos = 0; faulty_pos < eq_pos; ++faulty_pos) {
        // Try to "fix" it by changing it to any valid character
        for (char candidate_char : all_chars) {
            
            // Check if the change corresponds to a single LED toggle
            if (count_segment_diff(displayed_patterns[faulty_pos], patterns.at(candidate_char)) == 1) {
                
                std::string test_lhs_str;
                bool possible = true;
                
                // Reconstruct the LHS string with the potential fix
                for (int j = 0; j < eq_pos; ++j) {
                    if (faulty_pos == j) {
                        test_lhs_str += candidate_char;
                    } else {
                        // Other characters must be perfectly formed
                        if (reverse_patterns.count(displayed_patterns[j])) {
                            test_lhs_str += reverse_patterns.at(displayed_patterns[j]);
                        } else {
                            possible = false; // Another char is malformed, invalid hypothesis
                            break;
                        }
                    }
                }
                
                if (possible && evaluate_lhs(test_lhs_str) == rhs_val) {
                    std::cout << faulty_pos + 1 << std::endl;
                    return;
                }
            }
        }
    }
}

int main() {
    fast_io();
    setup_patterns();
    solve();
    return 0;
}