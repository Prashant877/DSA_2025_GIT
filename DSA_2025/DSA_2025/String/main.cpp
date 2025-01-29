//
//  main.cpp
//  String
//
//  Created by Prashant on 24/01/25.
//

#include <iostream>
#include <string>  // For string handling

using namespace std;

/*int main() {
    string str;

    // Input a single word
    cout << "Enter a word: ";
    cin >> str;
    cout << "You entered the word: " << str << endl;

    // Clear the buffer (to allow input after cin >>)
    cin.ignore();

    // Input a full line (including spaces)
    cout << "Enter a sentence: ";
    getline(cin, str);
    cout << "You entered the sentence: " << str << endl;

    return 0;
}*/
#include <iostream>
#include <string>
using namespace std;

void reverseString(string &str) {
    size_t start = 0, end = str.length() - 1; // Use size_t for indices

    // Reverse the string in place using two pointers
    while (start < end) {
        swap(str[start], str[end]);
        start++;
        end--;
    }
}

int main() {
    int T; // Number of test cases
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

    while (T--) {
        string str;
        getline(cin, str); // Read the string input (including spaces if any)

        reverseString(str); // Reverse the string in place
        cout << str << endl; // Print the reversed string
    }

    return 0;
}
