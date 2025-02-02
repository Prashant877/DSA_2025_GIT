//
//  main.cpp
//  PostEvaluator
//
//  Created by Prashant on 01/02/25.
//

#include <iostream>
#include <stack>
#include <cmath> // For pow()
using namespace std;

int postfixEval(string s) {
    stack<int> st;

    for (int i = 0; i < s.length(); i++) {
        // If character is a digit, push it to stack
        if (s[i] >= '0' && s[i] <= '9') {
            st.push(s[i] - '0'); // Convert char to int
        }
        else if (s[i] == ' ') {
            continue; // Ignore spaces
        }
        else { // Operator case
            if (st.size() < 2) {
                cerr << "Invalid expression!" << endl;
                return -1;
            }

            int operand2 = st.top(); st.pop();
            int operand1 = st.top(); st.pop();

            switch (s[i]) {
                case '+': st.push(operand1 + operand2); break;
                case '-': st.push(operand1 - operand2); break;
                case '*': st.push(operand1 * operand2); break;
                case '/':
                    if (operand2 == 0) {
                        cerr << "Division by zero error!" << endl;
                        return -1;
                    }
                    st.push(operand1 / operand2);
                    break;
                case '^': st.push(pow(operand1, operand2)); break;
                default:
                    cerr << "Invalid operator: " << s[i] << endl;
                    return -1;
            }
        }
    }
    return st.top();
}

// Driver Code
int main() {
    cout << postfixEval("7 4 5 * + 2 0 + -") << endl; // Expected output: 25
}
