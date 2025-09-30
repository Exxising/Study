// 2023 05 18

#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
void PostOrder(int s, int e){
    if(s >= e) return;
    if(s == e-1){
        cout << v[s] << '\n';
        return;
    }

    int idx = s+1;
    while(idx < e){
        if(v[s] < v[idx]) break;
        idx++;
    }

    PostOrder(s+1, idx);
    PostOrder(idx, e);
    cout << v[s] << '\n';
    return;
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    
    while(cin >> n){
        v.push_back(n);
    }
    PostOrder(0, v.size());
}