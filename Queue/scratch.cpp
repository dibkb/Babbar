#include <iostream>
using namespace std;
class Queue {
    public:
    int size;
    int front;
    int rear;
    int *arr;

    Queue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void push(int val){
        if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = val;
        }else{
            rear++;
            arr[rear] = val;
        }
    }
    void pop(){
        if(front == -1 && rear == -1){
            cout << "Queue underflow";
        }else{
            arr[front] = -1;
            front++;
        }
    }
    int getSize(){
        if(front == -1 && rear == -1)
            return 0;
        return rear - front + 1;
    }
    void printQueue(){
        for (int i = 0; i < size; ++i){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Queue qu(5);
    qu.push(10);
    qu.push(50);
    qu.push(60);
    qu.pop();
    qu.pop();
    qu.printQueue();
    cout << qu.getSize();
    return 0;
}