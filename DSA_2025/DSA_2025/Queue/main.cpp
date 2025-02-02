//
//  main.cpp
//  Queue
//
//  Created by Prashant on 30/01/25.
//

#include <iostream>
#include "queue"
using namespace std;

class Queue{
public:
    int *arr;
    
    int front;
    int rear;
    int size;
    
    Queue(){
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    
    void push(int val){
        if(rear == size-1){
            cout<<"Queue Overflow "<<endl;
            return;
        }
        
        rear++;
        arr[rear] = val;
        if(front == -1){
            front++;
        }
    }
        
    void pop(){
            
        if(front == -1){
            cout<<"Queue is empty "<<endl;
            return;
        }
        front++;
    }
    
};

int main(){
    queue<int> q;
    
    q.push(1);
    
}
