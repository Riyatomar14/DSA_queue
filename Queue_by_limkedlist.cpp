// queue by linked list
#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    //constructor
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
class queue{
    node* front;
    node* rear;
    public:
    
    queue(){
        front=NULL;
        rear=NULL;
    }
    
    bool isEmpty(){
        if(front==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    
    void enqueue(int data){
        node* new_node = new node(data);

        // If queue is empty, the new node is both the front and rear
        if (this->isEmpty()) {
            front = rear = new_node;
            return;
        }
        else{
            //if queue is not empty,
            rear->next=new_node;
            rear=new_node;
        }
    }
    
    void dequeue(){
        if(this->isEmpty()) {
            cout<<"queue is underflow"<<endl;
            return;
        }    
             
        node* temp = front;
        front = front->next;

        // If front becomes nullptr, then change rear also
        // to nullptr
        if (front == NULL)
            rear = NULL;

        // Deallocate memory of the old front node
        delete temp;
    }
    int getFront() {
      
      // Checking if the queue is empty
        if (this->isEmpty()) {
            cout << "Queue is empty\n";
            return -1 ;
        }
        return front->data;
    }


    int getRear() {

      // Checking if the queue is empty
        if (this->isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
      
        return rear->data;
    }
};

int main() {
    queue q;

   
    q.enqueue(10);
    q.enqueue(20);

    cout << "Queue Front: " << q.getFront() << endl;
    cout << "Queue Rear: " << q.getRear() << endl;

    q.dequeue();
    q.dequeue();

    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);


    // Display the front and rear elements of the queue
    cout << "Queue Front: " << q.getFront() << endl;
    cout << "Queue Rear: " << q.getRear() << endl << endl;

    return 0;
}
