#include<iostream>
#include<stack>
using namespace std;

char corresponding(char ch){
    if(ch == '('){
        return ')';
    }
    else if(ch == '['){
        return ']';
    }
    else if(ch == '{'){
        return '}';
    }
}

bool isWellParentesized(string s){

    stack<char> st;
    for(int i=0; i<s.length(); i++){

        char ch = s[i];

        if(ch == '(' || ch == '[' || ch == '{'){
            st.push(ch);
        }
        else if(ch == ')' || ch == ']' || ch == '}'){
            if(!st.empty() && st.top() == corresponding(ch)){
                st.pop();
            }
            else {
                return false;
            }
        }
    }

    return st.empty();
}
 
int main(){

    string s;
    cout << "Enter the expression: ";
    cin >> s;

    if(isWellParentesized(s)){
        cout << "Given Expression is Well Parenthesized." << endl;
    }
    else {
        cout << "Given Expression is not Well Parenthesized." << endl;
    }

    return 0;
}