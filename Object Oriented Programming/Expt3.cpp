#include<iostream>
using namespace std;

#define SIZE 100

class Publication {
    protected:
    string title;
    float price;

    public:
    void setData(){
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter price: ";
        cin >> price;
    }

    void getData() {
        cout << "-----------------------------------" << endl;
        cout << "Title: " << title << endl;
        cout << "Price: Rs. " << price << endl;
    }
};

class book : public Publication {
    int pages;

    public:

    book() {
        pages = 0;
    }

    void setData(){
        Publication::setData();
        cout << "Enter No. of Pages: ";
        cin >> pages;
    }

    void getData(){
        Publication::getData();
        try {
            if(pages < 0)
                throw pages;
        }
        catch(int p){
            cout << "ERROR: Invalid Pages: " << p << endl;
            pages = 0;
        }
        cout << "Pages: " << pages << endl;
    }
};

class tape : public Publication {
    float playtime;

    public:

    tape(){
        playtime = 0.0;
    }

    void setData(){
        Publication::setData();
        cout << "Enter Playtime of the tape in minutes: ";
        cin >> playtime;
    }

    void getData(){
        Publication::getData();
        try {
            if(playtime < 0)
                throw playtime;
        }
        catch(float p){
            cout << "ERROR: Invalid Playtime: " << p << endl;
            playtime = 0;
        }
        cout << "Playtime: " << playtime << endl;
    }
};

int main() {

    int choice;
    book B[SIZE];
    tape T[SIZE];
    int bookCount = 0, tapeCount = 0;

    do {
        cout << "********** Menu **********" << endl;
        cout << "1. Add book" << endl;
        cout << "2. Add tape" << endl;
        cout << "3. Display book" << endl;
        cout << "4. Display tape" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                B[bookCount++].setData();
                break;
            case 2:
                T[tapeCount++].setData();
                break;
            case 3:
                for(int i=0; i<bookCount; i++){
                    B[i].getData();
                }
                break;
            case 4:
                for(int i=0; i<tapeCount; i++){
                    T[i].getData();
                }
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid Choice" << endl;
        }
        cout << "\n\n";
    }
    while(choice != 5);

    return 0;
}