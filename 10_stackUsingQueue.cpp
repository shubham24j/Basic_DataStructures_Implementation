#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
    int currentSize;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        currentSize = 0;
    }

    void enQueue(int ele) {
        Node* newNode = new Node(ele);

        if (currentSize == 0) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        currentSize++;
    }

    int deQueue() {
        if (currentSize == 0) {
            return INT_MIN; // or throw exception
        }

        int ele = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        currentSize--;
        return ele;
    }

    int peekFront() {
        if (currentSize == 0) {
            return INT_MIN; // or throw exception
        }
        return front->data;
    }

    int size() {
        return currentSize;
    }
};

class Stack {
private:
    Queue qu;
    int currentSize = 0;

public:
    void push(int ele) {
        qu.enQueue(ele);

        for (int i = 0; i < currentSize; i++) {
            qu.enQueue(qu.deQueue());
        }

        currentSize++;
        cout << ele << " is successfully pushed into the stack." << endl;
    }

    int pop() {
        if (currentSize == 0) {
            cout << "Stack Underflow." << endl;
            return INT_MIN;
        }

        int ele = qu.deQueue();
        currentSize--;
        return ele;
    }

    int peek() {
        if (currentSize == 0) {
            cout << "Stack Underflow." << endl;
            return INT_MIN;
        }
        return qu.peekFront();
    }

    int size() {
        return currentSize;
    }
};

int main() {
    Stack st;
    st.push(100);
    st.push(200);
    st.push(300);
    st.push(400);

    cout << "Top of the stack is " << st.peek() << endl;

    cout << "Popped element is " << st.pop() << endl;
    cout << "Popped element is " << st.pop() << endl;

    cout << "Top of the stack is " << st.peek() << endl;

    return 0;
}
