#include<iostream>
using namespace std;

class Deque {
    int front;
    int rear;
    int size;
    int* arr;

    public:
    Deque(int n){
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

    void push_front(int d){

        if(isFull()){
            cout << "Deque is Full" << endl;
            return;
        }

        if(front == 0){
            front = size-1;
        }
        else if(front == -1){
            front = rear = 0;
        }
        else {
            front--;
        }
        arr[front] = d;
    }

    void push_back(int d){

        if(isFull()){
            cout << "Deque is Full" << endl;
            return;
        }
        
        if(front == -1){
            front = rear = 0;
        }
        else if(rear == size-1) {
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = d;
    }

    void pop_front() {

        if(isEmpty()){
            cout << "Deque is Empty" << endl;
            return;
        }
        
        cout << arr[front] << " Popped from front." << endl;
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

    void pop_back() {

        if(isEmpty()){
            cout << "Deque is Empty" << endl;
            return;
        }

        cout << arr[rear] << " Popped from back." << endl;
        arr[rear] = -1;
        if(front == rear){
            front = rear = -1;
        }
        else if(rear == 0){
            rear = size-1;
        }
        else {
            rear--;
        }
    }

    void display() {
        if(isEmpty()){
            cout << "Deque is Empty" << endl;
            return;
        }

        cout << "Deque: ";
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
    cout << "Enter the size of the Queue to be created: ";
    cin >> n;

    Deque dq(n);
    cout << "Deque of size " << n << " created successfully.\n\n";

    int choice = -1, x;
    while(choice != 6){

        cout << "******** Menu ********" << endl;
        cout << "1. Push Element at front" << endl;
        cout << "2. Push Element at back" << endl;
        cout << "3. Pop Element from front" << endl;
        cout << "4. Pop Element from back" << endl;
        cout << "5. Display Deque" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                cout << "Enter element: ";
                cin >> x;
                dq.push_front(x);
                break;
            case 2:
                cout << "Enter element: ";
                cin >> x;
                dq.push_back(x);
                break;
            case 3:
                dq.pop_front();
                break;
            case 4:
                dq.pop_back();
                break;
            case 5:
                dq.display();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid Choice\n";
        }
        cout << "\n\n";
    }
}