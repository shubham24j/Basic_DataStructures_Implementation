#include<iostream>
#include<limits.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = nullptr;
    }

    Node(int d, Node* n){
        data = d;
        next = n;
    }

    ~Node(){
        cout << "Node with value " << data << " is deleted." << endl;
    }
};

class Stack{
private:
    Node* top;

public:
    Stack(){
        top = nullptr;
    }

    void push(int ele){
        Node* newNode = new Node(ele, top);

        top = newNode;

        cout << top->data << " is successfully pushed in the stack." << endl;
    }

    int pop(){
        if(top == nullptr){
            cout << "Stack Underflow" << endl;
            return INT_MIN;
        }

        int ele = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;      
        return ele;
    }

    int peak(){
        if(top == nullptr){
            cout << "Stack Underflow" << endl;
            return INT_MIN;
        }

        int ele = top->data;
        return ele;
    }
};

int main(){
    Stack st;
    st.push(9);
    st.push(82);
    cout << "Top of the stack is: " << st.peak() << endl;
    st.pop();
    cout << "Top of the stack is: " << st.peak() << endl;
    return 0;
}
