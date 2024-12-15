#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear, capacity, currentSize;
    int* queue;

public:
    CircularQueue(int size) {
        capacity = size;
        queue = new int[capacity];
        front = -1;
        rear = -1;  
        currentSize = 0;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    bool isFull() {
        return currentSize == capacity;
    }

    bool enQueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return false;
        }

        rear = (rear + 1) % capacity;

        if (front == -1) {
            front = 0;
        }

        queue[rear] = value;
        currentSize++;
        cout << value << " enqueued to queue\n";
        return true;
    }

    int deQueue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return -1; 
        }

        int data = queue[front];
        front = (front + 1) % capacity;
        currentSize--;

        if (currentSize == 0) {
            front = -1;
            rear = -1;
        }

        return data;
    }

    int peekFront() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1; 
        }
        return queue[front];
    }

    int peekRear() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1; 
        }
        return queue[rear];
    }

    int size() {
        return currentSize;
    }
};


int main() {
    CircularQueue cq(5);

    cq.enQueue(10);
    cq.enQueue(20);
    cq.enQueue(30);
    cq.enQueue(40);

    cout << "Front element: " << cq.peekFront() << endl;
    cout << "Rear element: " << cq.peekRear() << endl;

    cout << cq.deQueue() << " dequeued from queue\n";
    cout << "Front element: " << cq.peekFront() << endl;

    cq.enQueue(50);
    cq.enQueue(60);

    cout << "Queue size: " << cq.size() << endl;
    cout << "Rear element: " << cq.peekRear() << endl;

    cq.~CircularQueue();

    return 0;
}
