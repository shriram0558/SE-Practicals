#include<iostream>
#include<map>
using namespace std;

int main(){

    map<string, long long> population;
    population["Maharashtra"] = 7026357;
    population["Rajasthan"] = 6578936;
    population["Karanataka"] = 6678993;
    population["Punjab"] = 5789032;
    population["West Bengal"] = 6676291;

    int choice;
    string state;
    auto it = population.begin();

    do {
        cout << "*********** Menu ***********" << endl;
        cout << "1. Get population of a state" << endl;
        cout << "2. Add population of a state" << endl;
        cout << "3. Display Population" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter name of State: ";
                cin >> state;
                it = population.find(state);
                if(it != population.end()){
                    cout << "Population of " << it->first << " is " << it->second << endl;
                }
                else {
                    cout << "Key not Found." << endl;
                }
                break;
            case 2:
                cout << "Enter name of State: ";
                cin >> state;
                cout << "Enter population of the State: ";
                cin >> population[state];
                break;
            case 3:
                for(auto i : population){
                    cout << i.first << ": " << i.second << endl;
                }
                break;
            case 4:
                exit(0);
            default: 
                cout << "Invalid Choice" << endl;
        }
        cout << "\n\n";
    }
    while(choice != 4);

    return 0;
}