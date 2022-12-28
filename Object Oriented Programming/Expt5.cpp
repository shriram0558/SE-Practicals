#include<iostream>
using namespace std;

template<typename T>
void selectionSort(T* arr, int n){
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

template<typename T>
void input(T* arr, int n){
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
}

template<typename T>
void output(T* arr, int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<typename T>
void solve() {
    int n;
    cout << "Enter size of the Array: ";
    cin >> n;
    T* a = new T[n];

    cout << "Enter Array: ";
    input(a, n);
    selectionSort(a, n);
    cout << "Sorted Array: ";
    output(a, n);
}

int main(){

    int choice;

    do {
        cout << "********** Menu **********" << endl;
        cout << "1. Integer Array" << endl;
        cout << "2. Float Array" << endl;
        cout << "3. string Array" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                solve<int>();
                break;
            case 2:
                solve<float>();
                break;
            case 3:
                solve<string>();
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