//
//  main.cpp
//  Balancing
//
//  Created by Prashant on 30/01/25.
//

#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string s, size_t size) {  // Use size_t instead of int
    stack<char> st;

    for (size_t i = 0; i < size; i++) {  // Use size_t for iteration
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (st.empty()) return false;  // Extra closing bracket
            
            char top = st.top();
            st.pop();

            // Check for matching pairs
            if ((s[i] == ')' && top != '(') ||
                (s[i] == '}' && top != '{') ||
                (s[i] == ']' && top != '[')) {
                return false;
            }
        }
    }

    return st.empty();  // Stack should be empty if balanced
}

int main() {
    string expr = "{[()]}";
    size_t size = expr.length();  // Use size_t for correct type

    if (isBalanced(expr, size)) {
        cout << "Balanced\n";
    } else {
        cout << "Unbalanced\n";
    }

    return 0;
}
