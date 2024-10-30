// circular queue
#include <iostream>
using namespace std;

class CircularQueue {
    int* arr;
    int front;
    int rear;
    int size;

public: 
    CircularQueue() {
        size = 100001;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // to push/insert
    bool enqueue(int value) {
        // check if queue is full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            cout << "Queue is Full" << endl;
            return false;
        }
        // empty queue - first element to push
        else if (front == -1) {
            front = rear = 0;
        }
        // front is not at the beginning, so move the rear to the start of the array (circular behavior)
        else if (rear == size - 1 && front != 0) {
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    // to delete/pop
    int dequeue() {
        // check if queue is empty
        if (front == -1) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        
        int ans = arr[front];
        arr[front] = -1;

        // single element in the queue
        if (front == rear) {
            front = rear = -1;
        }
        // front is at the end of the array, so move it to the start (circular behavior)
        else if (front == size - 1) {
            front = 0;
        }
        else {
            front++;
        }
        return ans;
    }

    // print the queue elements
    void printQueue() {
        if (front == -1) {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Queue elements are: ";
        if (rear >= front) {
            // If rear is ahead of or at front, print linearly from front to rear
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        } else {
            // Queue is wrapped around
            for (int i = front; i < size; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;

    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.printQueue(); // Output: Queue elements are: 10 20 30

    q.dequeue();
    q.printQueue(); // Output: Queue elements are: 20 30

    return 0;
}
