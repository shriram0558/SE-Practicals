#include<iostream>
#include<stack>
using namespace std;

int prec(char ch){
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s){

    string ans = "";
    stack<char> st;
    for(int i=0; i<s.length(); i++){

        char ch = s[i];

        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            ans += ch;
        }
        else if(ch == '('){
            st.push(ch);
        }
        else if(ch == ')'){
            while(st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while(!st.empty() && prec(ch) <= prec(st.top())){
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}
 
int main(){
    
    string s;
    cout << "Enter infix expression: ";
    cin >> s;

    string ans = infixToPostfix(s);
    cout << "Postfix Expression: " << ans << endl;

    return 0;
}