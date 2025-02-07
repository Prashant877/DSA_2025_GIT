//
//  main.cpp
//  ReverseQueue
//
//  Created by Prashant on 30/01/25.
//
/*
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverseQueue(queue<int> &q) {
    stack<int> s;

    // Step 1: Move all elements from queue to stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Move all elements from stack back to queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

void printQueue(queue<int> q) { // Function to print queue without modifying it
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "Original Queue: ";
    printQueue(q);

    reverseQueue(q);

    cout << "Reversed Queue: ";
    printQueue(q);

    return 0;
}*/
// reverse first K elements of queue

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> kReverseQueue(queue<int> q, int k) {
    if (q.empty() || k <= 0 || k > (int)q.size()) {  // Explicit cast to int
        return q;
    }

    stack<int> s;

    // Step 1: Push first k elements into stack
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Push stack elements back into queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Move the remaining (n-k) elements to the back of the queue
    int remainingElements = (int)q.size() - k;  // Explicit cast here
    for (int i = 0; i < remainingElements; i++) {
        q.push(q.front());
        q.pop();
    }

    return q;
}

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);

    int k = 5;

    cout << "Original Queue: ";
    printQueue(q);

    queue<int> reversedQueue = kReverseQueue(q, k);

    cout << "Queue after k-Reversal: ";
    printQueue(reversedQueue);

    return 0;
}

