// 2023 05 22

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int precedence(const char& oper){
    if(oper == '(' || oper == ')')      return 0;
    else if(oper == '*' || oper == '/') return 2;
    else if(oper == '+' || oper == '-') return 1;

    return 0;
}

int main(){
    stack<char> st;
    string      str;
    cin >> str;

    for(int i=0; i<str.length(); i++){
        if(str[i] == '('){
            st.push(str[i]);
        } else if(str[i] == ')'){
            while(!st.empty()){
                if(st.top() == '('){
                    st.pop();
                    break;
                } else {
                    cout << st.top();
                    st.pop();
                }
            }
        } else if(str[i] == '*' || str[i] == '+' || str[i] == '-' || str[i] == '/'){
            while(!st.empty()){
                if(precedence(str[i]) <= precedence(st.top())){
                    cout << st.top();
                    st.pop();
                } else break;
            }
            st.push(str[i]);
        } else cout << str[i];
    }
    
    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout << '\n';
}