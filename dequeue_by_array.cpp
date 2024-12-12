#include <iostream>
using namespace std;

class ArrayDeque {
    int* deque;
    int front, rear, size;

public:
    ArrayDeque(int size) {
        this->size = size;
        deque = new int[size];
        front = -1;
        rear = -1;
    }

    ~ArrayDeque() {
        delete[] deque;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueueFront(int data) {
        if (isFull()) {
            cout << "Deque is full!" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + size) % size;
        }
        deque[front] = data;
    }

    void enqueueRear(int data) {
        if (isFull()) {
            cout << "Deque is full!" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        deque[rear] = data;
    }

    int dequeueFront() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        int data = deque[front];
        if (front == rear) { // Single element case
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return data;
    }

    int dequeueRear() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        int data = deque[rear];
        if (front == rear) { // Single element case
            front = rear = -1;
        } else {
            rear = (rear - 1 + size) % size;
        }
        return data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        int i = front;
        while (true) {
            cout << deque[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    ArrayDeque dq(5);

    dq.enqueueRear(10);
    dq.enqueueRear(20);
    dq.enqueueFront(5);
    dq.display(); // Output: 5 10 20

    cout << "Dequeue Front: " << dq.dequeueFront() << endl; // Output: 5
    dq.display(); // Output: 10 20

    cout << "Dequeue Rear: " << dq.dequeueRear() << endl; // Output: 20
    dq.display(); // Output: 10

    return 0;
}
