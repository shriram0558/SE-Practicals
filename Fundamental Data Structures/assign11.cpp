#include<iostream>
using namespace std;

class Queue {

    int front;
    int rear;
    int size;
    int* arr;

    public:
    Queue(int n){
        this->size = n;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void enqueue(int d){

        if(rear == size){
            cout << "Queue is Full" << endl;
        }
        else {
            arr[rear] = d;
            rear++;
        }
    }

    void dequeue(){

        if(front == rear){
            cout << "Queue is Empty" << endl;
        }
        else {
            front++;
        }
    }

    void display() {

        if(front == rear){
            cout << "Queue is Empty" << endl;
        }
        else{
            cout << "Queue: ";
            for(int i=front; i<rear; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {

    int n;
    cout << "Enter the size of the Queue to be created: ";
    cin >> n;

    Queue q(n);

    cout << "Queue of size " << n << " created successfully.\n\n";

    int choice = -1, x;
    while(choice != 4){

        cout << "******** Menu ********" << endl;
        cout << "1. Add job" << endl;
        cout << "2. Remove job" << endl;
        cout << "3. Display Jobs" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                cout << "Enter Job no: ";
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