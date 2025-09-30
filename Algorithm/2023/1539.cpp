// 2023 05 19

#include <iostream>
#include <set>
typedef long long ll;
using namespace std;

int main(){
    set<int> s;
    ll sum = 0;
    int n, height[250001];

    cin >> n;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;

        set<int>::iterator it = s.lower_bound(val);
        ll left, right;
        
        if(it != s.begin()){
            set<int>::iterator leftIt = it;
            left = height[*(--leftIt)]; 
        } else left = 0;

        if (it!=s.end()) right = height[*it];
        else right = 0;

        height[val] = max(left, right) + 1;
        s.insert(val);
        sum += height[val]; 
    }
    cout << sum << '\n';
}