#include<iostream>
using namespace std;

class Node {
    public:
    int prn;
    string name;
    Node* next;

    Node(int prn, string name){
        this->prn = prn;
        this->name = name;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int prn, string name){
    
    Node* temp = new Node(prn, name);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &head, int prn, string name){

    Node* temp = new Node(prn, name);

    if(head == NULL){
        head = temp;
    }
    else {
        Node* travel = head;
        while(travel->next != NULL){
            travel = travel->next;
        }
        travel->next = temp;
    }
}

void insertMember(Node* &head, int prn, string name){

    Node* temp = new Node(prn, name);

    if(head == NULL){
        head = temp;
    }
    else if(head->next == NULL){
        head->next = temp;
    }
    else {
        temp->next = head->next;
        head->next = temp;
    }
}

void deleteHead(Node* &head){

    if(head == NULL){
        cout << "List is Empty." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
    cout << "President Deleted Successfully." << endl;
}

void deleteTail(Node* &head){

    if(head == NULL){
        cout << "List is Empty." << endl;
        return;
    }

    if(head->next == NULL) {
        Node* temp = head;
        head = NULL;
        delete temp;
    }
    else {
        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        Node* x = temp->next;
        temp->next = NULL;
        delete x;
    }
    cout << "Secretary Deleted Successfully." << endl;
}

void deleteMember(Node* &head, int prn) {

    if(head == NULL){
        cout << "List is Empty." << endl;
        return;
    }

    if(head->prn == prn){
        deleteHead(head);
    }
    else {
        Node* prev = NULL;
        Node* curr = head;
        while(curr != NULL && curr->prn != prn){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        delete curr;
    }
    cout << "Member Deleted Successfully." << endl;
}

void displayList(Node* &head){
    
    if(head == NULL){
        cout << "List is Empty." << endl;
        return;
    }

    Node* travel = head;
    cout << "---------------------------" << endl;
    while(travel != NULL){
        cout << "PRN: " << travel->prn << endl;
        cout << "Name: " << travel->name << endl;
        cout << endl;
        travel = travel->next;
    }
    cout << "---------------------------" << endl;
}

Node* concatenate(Node* head1, Node* head2){

    if(head1 == NULL){
        return head2;
    }

    Node* travel = head1;
    while(travel->next != NULL){
        travel = travel->next;
    }
    travel->next = head2;
    return head1;
}

int main() {

    Node* div1 = NULL;
    Node* div2 = NULL;
    Node* conc = NULL;

    int choice = -1, p;
    string n;
    while(choice != 16){

        cout << "************ Menu ************" << endl;
        cout << "1. Add President to Division 1" << endl;
        cout << "2. Add President to Division 2" << endl;
        cout << "3. Add Secretary to Division 1" << endl;
        cout << "4. Add Secretary to Division 2" << endl;
        cout << "5. Add Member to Division 1" << endl;
        cout << "6. Add Member to Division 2" << endl;
        cout << "7. Delete President from Division 1" << endl;
        cout << "8. Delete President from Division 2" << endl;
        cout << "9. Delete Secretary from Division 1" << endl;
        cout << "10. Delete Secretary from Division 2" << endl;
        cout << "11. Delete Member to Division 1" << endl;
        cout << "12. Delete Member to Division 2" << endl;
        cout << "13. Display Members in Division 1" << endl;
        cout << "14. Display Members in Division 2" << endl;
        cout << "15. Concatenate two lists" << endl;
        cout << "16. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                cout << "Enter PRN of President: ";
                cin >> p;
                cout << "Enter name of President: ";
                cin >> n;
                insertAtHead(div1, p, n);
                break;
            case 2:
                cout << "Enter PRN of President: ";
                cin >> p;
                cout << "Enter name of President: ";
                cin >> n;
                insertAtHead(div2, p, n);
                break;
            case 3:
                cout << "Enter PRN of Secretary: ";
                cin >> p;
                cout << "Enter name of Secretary: ";
                cin >> n;
                insertAtTail(div1, p, n);
                break;
            case 4:
                cout << "Enter PRN of Secretary: ";
                cin >> p;
                cout << "Enter name of Secretary: ";
                cin >> n;
                insertAtTail(div2, p, n);
                break;
            case 5:
                cout << "Enter PRN of member: ";
                cin >> p;
                cout << "Enter name of member: ";
                cin >> n;
                insertMember(div1, p, n);
                break;
            case 6:
                cout << "Enter PRN of member: ";
                cin >> p;
                cout << "Enter name of member: ";
                cin >> n;
                insertMember(div2, p, n);
                break;
            case 7:
                deleteHead(div1);
                break;
            case 8:
                deleteHead(div2);
                break;
            case 9:
                deleteTail(div1);
                break;
            case 10:
                deleteTail(div2);
                break;
            case 11:
                cout << "Enter PRN of member to delete: ";
                cin >> p;
                deleteMember(div1, p);
                break;
            case 12:
                cout << "Enter PRN of member to delete: ";
                cin >> p;
                deleteMember(div2, p);
                break;
            case 13:
                displayList(div1);
                break;
            case 14:
                displayList(div2);
                break;
            case 15:
                conc = concatenate(div1, div2);
                cout << "Concatenated List: " << endl;
                displayList(conc);
                break;
            case 16:
                return 0;
            default:
                cout << "Invalid Choice\n";
        }
        cout << "\n\n";
    }

    return 0;
}