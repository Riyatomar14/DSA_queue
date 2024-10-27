// STL queue
#include <iostream>
#include<queue>
using namespace std;

int main() {
    //create a queue
    queue<int> q;
    //push
    q.push(11);
    q.push(13);
    q.push(56);
    cout<<"front of q "<<q.front()<<endl;
    cout<<"Back of q "<<q.back()<<endl;
    //size
    cout<<"size of the queue is "<< q.size()<<endl;
    //pop
    q.pop();
    q.pop();
    q.pop();
    cout<<"size of the queue is "<< q.size()<<endl;
    //empty or not
    if(q.empty()){
        cout<<" QUEUE IS EMPTY"<<endl;
    }
    else{
        cout<<"QUEUE IS NOT EMPTY"<<endl;
    }
    
    
    return 0;
}
