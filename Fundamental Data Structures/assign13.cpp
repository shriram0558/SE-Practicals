#include<iostream>
using namespace std;

class circularQueue {
    int front;
    int rear;
    int size;
    int* arr;

    public:
    circularQueue(int n){
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        if(front == -1)
            return true;
        return false;
    }

    bool isFull() {
        if((rear+1)%size == front)
            return true;
        return false;
    }

    void enqueue(int d){

        if(isFull()){
            cout << "Queue is Full" << endl;
            return;
        }
        
        if(front == -1){
            front = rear = 0;
            arr[rear] = d;
        }
        else if(rear == size-1) {
            rear = 0;
            arr[rear] = d;
        }
        else {
            rear++;
            arr[rear] = d;
        }
        arr[rear] = d;
    }

    void dequeue() {

        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return;
        }
        
        arr[front] = -1;
        if(front == rear){
            front = rear = -1;
        }
        else if(front == size-1){
            front = 0;
        }
        else {
            front++;
        }
    }

    void display() {
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Queue: ";
        if(rear >= front){
            for(int i=front; i<=rear; i++) 
                cout << arr[i] << " ";
        }
        else {
            for(int i=front; i<size; i++)
                cout << arr[i] << " ";
            for(int i=0; i<=rear; i++)
                cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    
    int n;
    cout << "Enter the size of the Circular Queue to be created: ";
    cin >> n;

    circularQueue q(n);
    cout << "Circular Queue of size " << n << " created successfully.\n\n";

    int choice = -1, x;
    while(choice != 4){

        cout << "******** Menu ********" << endl;
        cout << "1. Add order" << endl;
        cout << "2. Remove order" << endl;
        cout << "3. Display orders" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                cout << "Enter order no: ";
                cin >> x;
                q.enqueue(x);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid Choice\n";
        }
        cout << "\n\n";
    }

    return 0;
}