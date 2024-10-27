// queue by arrary
#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int front;
    int rear;
    int size;

public:
    Queue() {
        size = 100001;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    // push/insert the element
    void enqueue(int data) {
        // when rear is pointing next to the last element(n-1) in queue
        if (rear == size) {
            cout << "Queue is full" << endl;
        } else {
            arr[rear] = data;
            rear++;
        }
    }

    // pop the element
    int dequeue() {
        // if both point to the same, then empty
        if (front == rear) {
            return -1;
        } else {
            int ans = arr[front];
            front++;
            // to save the memory, we reset to initial state if queue is empty
            if (front == rear) {
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    bool isEmpty() {
        return front == rear;
    }

    int getFront() {
        if (front == rear) {
            return -1;
        } else {
            return arr[front];
        }
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    cout << "Front element: " << q.getFront() << endl; 
    cout << "Dequeue element: " << q.dequeue() << endl; 
    cout << "Dequeue element: " << q.dequeue() << endl; 
    cout << "Queue empty? " << q.isEmpty() << endl; 

    return 0;
}
