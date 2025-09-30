// 2023 12 8

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int p;
        cin >> p;
        if((double)p / ceil(sqrt(p)) > ceil(sqrt(p)) - 1){
            cout << ceil(sqrt(p)) * 4 << '\n';
        } else {
            cout << ceil(sqrt(p)) * 4 - 2 << '\n';
        }
    }
}