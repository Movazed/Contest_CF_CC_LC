#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define nl "\n"

using namespace std;

void Movazed() {
    string input_string;
    cin >> input_string;

    bool is_first_and_last_same = (input_string[0] == input_string[2]);
    bool is_middle_w = (input_string[1] == 'w');

    if (is_first_and_last_same && is_middle_w) {
        cout << "Cute" << nl;
    } else {
        cout << "No" << nl;
    }
}

int main() {
    fast_io;
    
    Movazed();

    return 0;
}