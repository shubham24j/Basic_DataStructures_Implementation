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

class Queue{
private:
    Node* start;
    Node* end;
    int size;

public:
    Queue(){
        start = nullptr;
        end = nullptr;
        size = 0;
    }

    ~Queue(){
        while(size != 0){
            deQueue();
        }
        cout << "The queue is destroyed." << endl;
    }

    void enQueue(int ele){
        Node* newNode = new Node(ele);

        if(size == 0){
            start = newNode;
            end = newNode;
        }else{
            end->next = newNode;
            end = end->next;
        }

        size++;
        cout << newNode->data << " is successfully pushed in the queue." << endl;
    }

    int deQueue(){
        if(start == nullptr){
            cout << "Queue Underflow" << endl;
            return INT_MIN;
        }

        int ele = start->data;
        Node* temp = start;
        start = start->next;
        if(start == nullptr){
            end = nullptr;
        }
        delete temp;     
        size--; 
        return ele;
    }

    int peekFront(){
        if(size == 0){
            cout << "Queue Underflow" << endl;
            return INT_MIN;
        }

        int ele = start->data;
        return ele;
    }

    int peekRear(){
        if(size == 0){
            cout << "Queue Underflow" << endl;
            return INT_MIN;
        }

        int ele = end->data;
        return ele;
    }
};

int main(){
    Queue q;
    q.enQueue(9);
    q.enQueue(82);
    q.enQueue(23);
    cout << "Front of the Queue is: " << q.peekFront() << endl;
    cout << "Rear of the Queue is: " << q.peekRear() << endl;
    q.deQueue();
    cout << "Front of the Queue is: " << q.peekFront() << endl;
    cout << "Rear of the Queue is: " << q.peekRear() << endl;
    q.deQueue();
    cout << "Front of the Queue is: " << q.peekFront() << endl;
    cout << "Rear of the Queue is: " << q.peekRear() << endl;
    q.deQueue();
    cout << "Front of the Queue is: " << q.peekFront() << endl;
    cout << "Rear of the Queue is: " << q.peekRear() << endl;
    q.deQueue();
    return 0;
}
