#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Personal_info {
    public:
    string name, dob;
    long long telephone_number;

    Personal_info() {
        name = "";
        dob = "";
        telephone_number = 0;
    }

    Personal_info(string n, string d, long long a) {
        name = n;
        dob = d;
        telephone_number = a;
    }
    
    friend bool comparename(Personal_info p1, Personal_info p2);
    friend bool comparedob(Personal_info p1, Personal_info p2);
    friend bool comparetelephone(Personal_info p1, Personal_info p2);

    void set_data() {
        cout << "Enter the Name: ";
        cin >> name;
        cout << "Enter the Data Of Birth: ";
        cin >> dob;
        cout << "Enter the Telephone NO: ";
        cin >> telephone_number;
    }

    void get_data() {
        cout << "Name:                  " << name << endl;
        cout << "Data of birth:         " << dob << endl;
        cout << "Telephone No:          " << telephone_number << endl<<endl;
    }
     
};

bool comparename(Personal_info p1, Personal_info p2) {
    if (p1.name < p2.name)
        return true;
    return false;
}

bool comparedob(Personal_info p1, Personal_info p2) {
    if (p1.dob < p2.dob)
        return true;
    return false;
}

bool comparetelephone(Personal_info p1, Personal_info p2) {
    if (p1.telephone_number < p2.telephone_number)
        return true;
    return false;
}

int main() {

    int choice;
    Personal_info p, s1;
    vector<Personal_info> v;

    do {
        cout << "********** Menu **********" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Display" << endl;
        cout << "3. Sort by Name" << endl;
        cout << "4. Sort by Date of Birth" << endl;
        cout << "5. Sort by Telephone no" << endl;
        cout << "6. Search by Name" << endl;
        cout << "7. Search by Date of Birth" << endl;
        cout << "8. Search by Telephone No" << endl;
        cout << "9. Break" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                p.set_data();
                v.push_back(p);
                break;
            case 2:
                for (int i=0; i<v.size(); i++){
                    v[i].get_data();
                }
                break;
            case 3:
                sort(v.begin(), v.end(), comparename);
                break;
            case 4:
                sort(v.begin(), v.end(), comparedob);
                break;
            case 5:
                sort(v.begin(), v.end(), comparetelephone);
                break;
            case 6:
                cout << "Enter the name: ";
                cin >> s1.name;
                if(binary_search(v.begin(), v.end(), s1, comparename))
                    cout << s1.name << " is present in the database.\n";
                else
                    cout << s1.name << " is not present in the data base.\n";
                break;
            case 7:
                cout << "Enter the date of birth: ";
                cin >> s1.dob;
                if(binary_search(v.begin(), v.end(), s1, comparedob))
                    cout << s1.dob << " is present in the database.\n";
                else
                    cout << s1.dob << " is not present in the database.\n";   
                break;
            case 8:
                cout << "Enter the telephone no.: ";
                cin >> s1.telephone_number;
                if(binary_search(v.begin(), v.end(), s1, comparetelephone))
                    cout << s1.telephone_number << " is present in the database.\n";
                else
                    cout << s1.telephone_number << " is not present in the database.\n";   
                break;
            case 9:
                return 0;
            default:
                cout << "Invalid Choice" << endl;
                break;
        }
        cout << "\n\n";
    }
    while(choice != 9);

    return 0;
}
