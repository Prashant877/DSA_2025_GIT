//
//  main.cpp
//  ReverseString
//
//  Created by Prashant on 30/01/25.
//

#include <iostream>
#include <stack>
using namespace std;

void reverseSentence(string s) {
    stack<string> st;
    string word = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            word += s[i];  // Append character to word
        } else {
            if (!word.empty()) {
                st.push(word);  // Push the word into stack
                word = "";  // Reset word
            }
        }
    }
    
    if (!word.empty()) {  // Push the last word (if any)
        st.push(word);
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    string str = "Hello how are you";  // Correct variable declaration
    reverseSentence(str);  // Pass the string correctly
    return 0;
}

