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
        // when rear is pointing next to the last element in queue
        if (rear == size) {
            cout << "Queue is full" << endl;
        } else {
            arr[rear] = data;
            rear++;
        }
    }

    // pop the element
    int dequeue() {
        // if both pointers are the same, then the queue is empty
        if (front == rear) {
            return -1;
        } else {
            int ans = arr[front];
            front++;
            // to save memory, reset to the initial state if the queue is empty
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
    
    void printQueue() {
        if (front == rear) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i < rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.printQueue();  
    cout << "Front element: " << q.getFront() << endl; 
    cout << "Dequeue element: " << q.dequeue() << endl; 
    q.printQueue();  // Print the queue after a dequeue operation
    cout << "Dequeue element: " << q.dequeue() << endl; 
    cout << "Queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; 

    return 0;
}
