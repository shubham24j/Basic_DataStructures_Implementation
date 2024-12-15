/* C++ program to implement basic stack  operations */
// All methods have Time complexity: O(1)
// But the space complexity is O(n) as we are using arrays

#include <bits/stdc++.h> 
using namespace std; 

#define CAPACITY 1000

class Stack { 
    int top; 
    int *st;

public: 

    Stack(int cap) {
        st = new int[cap];
        top = -1;
    } 

    bool isEmpty() { 
        return (top < 0); 
    } 

    bool ifFull() {
        return (top >= (CAPACITY - 1));
    }

    bool push(int ele) { 
        if (ifFull()) { 
            cout << "Stack Overflow"; 
            return false; 
        } else { 
            st[++top] = ele; 
            cout << ele << " pushed into stack\n"; 
            return true; 
        } 
    } 

    int pop() { 
        if (isEmpty()) { 
            cout << "Stack Underflow"; 
            return INT_MIN; 
        } else { 
            int ele = st[top--]; 
            cout << ele << " is poped out of the stack." << endl;
            return ele; 
        } 
    } 

    int peek() { 
        if (isEmpty()) { 
            cout << "Stack is Empty"; 
            return 0; 
        } else { 
            int ele = st[top]; 
            return ele; 
        } 
    } 

    int size() {
        return top + 1;
    }
};


int main() 
{ 
    class Stack s(100); 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    s.push(40);
    s.push(50);

    cout << "Size of stack is: " << s.size() << endl << endl;

    s.pop(); 
    
    //print top element of stack after popping 
    cout << "Top element is : " << s.peek() << endl << endl; 
     
    while(!s.isEmpty()) { 
        cout <<"Top element is: ";
        cout << s.peek() << endl;; 
        s.pop(); 
    } 

    cout << "\nSize of stack is: " << s.size() << endl;
    return 0; 
}