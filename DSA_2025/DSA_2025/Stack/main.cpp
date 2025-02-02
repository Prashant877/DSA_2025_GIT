//
//  main.cpp
//  Stack
//
//  Created by Prashant on 29/01/25.
//

#include <iostream>
using namespace std;

int main(){
    stack<int> st;
    
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    
    cout<<st.top()<<endl;
}
