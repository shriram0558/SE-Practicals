#include<iostream>
using namespace std;

class Node {
    public:
    int rollNo;
    Node* next;

    Node(int d) {
        rollNo = d;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);

    if(head == NULL){
        head = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

// Set of students who like both vanilla and butterscoth
void func1(Node* head1, Node* head2){

    Node* travel = head1;
    while(travel != NULL){
        Node* temp = head2;
        while(temp != NULL){
            if(temp->rollNo == travel->rollNo){
                cout << temp->rollNo << " ";
                break;
            }
            temp = temp->next;
        }
        travel = travel->next;
    }
    cout << endl;
}

// Set of students who like either vanilla or butterscoth or not both
void func2(Node* head1, Node* head2, Node* std) {

    Node* travel = std;

    while(travel != NULL){

        bool p1 = false, p2 = false;

        Node* temp = head1;
        while(temp != NULL){
            if(temp->rollNo == travel->rollNo){
                p1 = true;
                break;
            }
            temp = temp->next;
        }

        temp = head2;
        while(temp != NULL){
            if(temp->rollNo == travel->rollNo){
                p2 = true;
                break;
            }
            temp = temp->next;
        }

        if(!(p1 == true && p2 == true)){
            cout << travel->rollNo << " ";
        }
        travel = travel->next;
    }
    cout << endl;
}

// Set of students who like neither vanilla nor butterscotch
void func3(Node* head1, Node* head2, Node* std){
    Node* travel = std;
    while(travel != NULL){

        bool present = false;

        Node* temp = head1;
        while(temp != NULL){
            if(temp->rollNo == travel->rollNo){
                present = true;
                break;
            }
            temp = temp->next;
        }

        temp = head2;
        while(temp != NULL){
            if(temp->rollNo == travel->rollNo){
                present = true;
                break;
            }
            temp = temp->next;
        }

        if(present == false){
            cout << travel->rollNo << " ";
        }

        travel = travel->next;
    }
    cout << endl;
}

int main() {

    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* std = NULL;

    int n;

    cout << "Enter total number of students to add: ";
    cin >> n;
    cout << "Enter roll numbers to add: ";
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        insertAtHead(std, x);
    }

    cout << "Enter number of students who like Vanilla: ";
    cin >> n;
    cout << "Enter roll numbers to add: ";
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        insertAtHead(head1, x);
    }

    cout << "Enter number of students who like Butterscotch: ";
    cin >> n;
    cout << "Enter roll numbers to add: ";
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        insertAtHead(head2, x);
    }
    cout << "\n\n";

    int choice = -1;
    while(choice != 4){

        cout << "******** Menu ********" << endl;
        cout << "1. Get set of students who like both vanilla and butterscoth" << endl;
        cout << "2. Get set of students who like either vanilla or butterscoth or not both" << endl;
        cout << "3. Get set of students who like neither vanilla nor butterscotch" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                func1(head1, head2);
                break;
            case 2:
                func2(head1, head2, std);
                break;
            case 3:
                func3(head1, head2, std);
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