// 2024 09 05
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, s;
int arr[100001];

int main() {
    cin >> n >> s;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    int start = 0, end = 0, length = 100001;
    long long sum = 0;
    while(start < n){
        if(sum < s) {
            sum += arr[end];
            end++;
        }
        else {
            sum -= arr[start];
            start++;
        }
        // end가 범위 벗어나지 않도록 함
        if(end > n) continue;

        if(sum >= s){
            length = min(length, end - start);
        }
    }
    if(length == 100001){
        cout << 0 << '\n';
        return 0;
    }
    cout << length << '\n';

}