#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void solve() {
    stack<string> s;
    queue<string> q;
    queue<string> outStrQueue;

    // Based on the image example:
    // Stack (Top to Bottom): {"b", "Z", "5"}
    // Queue (Front to Rear): {"ka5c", "2", "Tys4zs", "4", "b8op", "0"}

    int stackSize;
    cout << "Enter number of elements in stack: ";
    cin >> stackSize;
    
    vector<string> tempStack;
    cout << "Enter stack elements (Top to Bottom):" << endl;
    for(int i = 0; i < stackSize; i++) {
        string val;
        cin >> val;
        tempStack.push_back(val);
    }
    // Push into stack in reverse to maintain "Top to Bottom" order from input
    for(int i = tempStack.size() - 1; i >= 0; i--) {
        s.push(tempStack[i]);
    }

    cout << "Enter number of elements in queue (Strings + Indices): ";
    int queueSize;
    cin >> queueSize;
    cout << "Enter queue elements (Front to Rear):" << endl;
    for(int i = 0; i < queueSize; i++) {
        string val;
        cin >> val;
        q.push(val);
    }

    // Processing
    while (!s.empty() && q.size() >= 2) {
        string stackChar = s.top();
        s.pop();

        string queueStr = q.front();
        q.pop();

        int index = stoi(q.front());
        q.pop();

        // Check if character matches at index
        // Safety check: ensure index is within string bounds
        if (index >= 0 && index < queueStr.length() && string(1, queueStr[index]) == stackChar) {
            outStrQueue.push(stackChar);
        } else {
            outStrQueue.push("-1");
        }
    }

    // Output Result
    cout << "\nOutput - outStrQueue (Front -> Rear): { ";
    while (!outStrQueue.empty()) {
        cout << "\"" << outStrQueue.front() << "\"" << (outStrQueue.size() > 1 ? ", " : "");
        outStrQueue.pop();
    }
    cout << " }" << endl;
}

int main() {
    solve();
    return 0;
}