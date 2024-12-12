#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LinkedListDeque {
    Node* front;
    Node* rear;

public:
    LinkedListDeque() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueueFront(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void enqueueRear(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeueFront() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        int data = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) { // Single element case
            rear = nullptr;
        } else {
            front->prev = nullptr;
        }
        delete temp;
        return data;
    }

    int dequeueRear() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        int data = rear->data;
        Node* temp = rear;
        rear = rear->prev;
        if (rear == nullptr) { // Single element case
            front = nullptr;
        } else {
            rear->next = nullptr;
        }
        delete temp;
        return data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedListDeque dq;

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
