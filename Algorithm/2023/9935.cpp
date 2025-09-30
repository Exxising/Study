// 2023 12 20

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<char> v;

    string str, bomb;
    cin >> str >> bomb;

    for(int i = 0; i<str.length(); ++i){
        v.push_back(str[i]);
        if(v.size() >= bomb.length()){
            int cnt = 0;
            for(int j=(v.size()) - bomb.length(), idx = 0; j<v.size(); ++j, ++idx){
                if(v[j] != bomb[idx]) break;
                else cnt++;
            }
            if(cnt == bomb.length()){
                for(int k = 0; k<bomb.length(); k++){
                    v.pop_back();
                }
            }
        }
    }

    if(v.empty()) cout << "FRULA" << '\n';
    else {
        for(auto i : v) cout << i;
        cout << '\n';
        return 0;
    }
}