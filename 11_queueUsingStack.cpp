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

    Node(int d, Node* n) {
        data = d;
        next = n;
    }
};

class Stack {
private:
    Node* top;
    int currentSize;

public:
    Stack() {
        top = nullptr;
        currentSize = 0;
    }

    ~Stack() {
        while (currentSize != 0) {
            pop();
        }
    }

    void push(int ele) {
        Node* newNode = new Node(ele, top);
        top = newNode;
        currentSize++;
    }

    int pop() {
        if (currentSize == 0) {
            cout << "Stack Underflow." << endl;
            return INT_MIN;
        }

        int ele = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        currentSize--;
        return ele;
    }

    int peek() {
        if (currentSize == 0) {
            cout << "Stack Underflow." << endl;
            return INT_MIN;
        }

        return top->data;
    }

    int size() {
        return currentSize;
    }
};

class Queue {
private:
    Stack stack1;
    Stack stack2;
    int currentSize;

public:
    Queue() {
        currentSize = 0;
    }

    ~Queue() {
        while (stack1.size() != 0) {
            stack1.pop();
        }
        cout << "Queue is completely deleted." << endl;
    }

    void enQueue(int ele) {
        while (stack1.size() != 0) {
            stack2.push(stack1.pop());
        }

        stack2.push(ele);

        while (stack2.size() != 0) {
            stack1.push(stack2.pop());
        }

        currentSize++;
        cout << ele << " is successfully enqueued into the Queue." << endl;
    }

    int deQueue() {
        if (currentSize == 0) {
            cout << "Queue Underflow." << endl;
            return INT_MIN;
        }

        int ele = stack1.pop();
        currentSize--;
        cout << ele << " is successfully dequeued from the Queue." << endl;
        return ele;
    }

    int peekFront() {
        if (currentSize == 0) {
            cout << "Queue Underflow." << endl;
            return INT_MIN;
        }

        return stack1.peek();
    }

    int peekRear() {
        if (currentSize == 0) {
            cout << "Queue Underflow." << endl;
            return INT_MIN;
        }

        while (stack1.size() != 0) {
            stack2.push(stack1.pop());
        }

        int ele = stack2.peek();

        while (stack2.size() != 0) {
            stack1.push(stack2.pop());
        }
        return ele;
    }
};

int main() {
    Queue q;
    q.enQueue(100);
    q.enQueue(200);
    q.enQueue(300);
    q.enQueue(400);
    q.enQueue(500);

    cout << "Front element: " << q.peekFront() << endl;
    cout << "Rear element: " << q.peekRear() << endl;

    q.deQueue();
    q.deQueue();

    cout << "Front element after two dequeues: " << q.peekFront() << endl;

    return 0;
}
