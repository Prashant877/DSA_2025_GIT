//
//  main.cpp
//  StackArray
//
//  Created by Prashant on 29/01/25.
//

#include <iostream>
using namespace std;

class MyStack{
public:
    int *arr;
    int top;
    int size;
    
    MyStack(){
        arr = new int[size];
        top = -1;
    }
    
    void push(int val){
        if(top == size-1){
            cout<<"Stack Overflow "<<endl;
            return;
        }
        top++;
        arr[top] = val;
    }
    
    int pop(){
        if(top < 0){
            cout<<"Stack Underflow "<<endl;
            return -1;
        }
        return arr[top--];
    }
    
    int peek(){
        if(top < 0){
            cout<<"Stack is empty "<<endl;
            return -1;
        }
        return arr[top];
    }
    
    bool isEmpty(){
        return top < 0;
    }
    
};

int main() {
    MyStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "Top element: " << s.peek() << endl;
    cout << s.pop() << " popped from stack\n";
    cout << "Top element after pop: " << s.peek() << endl;
    
    return 0;
}
