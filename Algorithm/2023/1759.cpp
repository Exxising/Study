// 2023 12 20

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n, c;
vector<char> v;
vector<char> str;
bool* check;

void print(){
    for(char i : str) cout << i;
    cout << '\n';
    return;
}

void password(int l, int s, int vow, int con){
    if(l == n){
        if(vow >= 1 && con >= 2) print();
        return;
    }

    for(int i = s; i<c; i++){
        if(check[i]) continue;
        check[i] = true;
        str.push_back(v[i]);
        if(v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u'){
            password(l+1, i, vow+1, con);
        } else password(l+1, i, vow, con+1);
        str.pop_back();
        check[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> c;
    check = new bool[c];

    for(int i = 0; i<c; i++){
        char temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    password(0, 0, 0, 0);
}