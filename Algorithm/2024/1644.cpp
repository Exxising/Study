// 2024 08 29

#include <iostream>
#include <vector>
using namespace std;
bool isPrime[4000001];
vector<int> prime;

void Prime(int n)
{
    // Initialize
    for(int i = 2; i<=n; i++){
        isPrime[i] = true;
    }

    for(int i = 2; i <= n; i++){
        if(isPrime[i]){
            for(int j = i+i; j<=n; j+=i) {
                isPrime[j] = false;
            }
        }
    }

    for(int i = 2; i<=n; i++){
        if(isPrime[i]) prime.push_back(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    if(n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    else if(n==2){
        cout << 1 << '\n';
        return 0;
    }

    Prime(n);
    
    int start = 0, end = 0, sum = 0, result = 0;
    int limit = prime.size() - 1;
    while(start < limit){
        if(sum < n)
        {
            sum += prime[end];
            end++;
        }
        else 
        {
            sum -= prime[start];
            start++;
        }
        if(sum == n) result++;
    }
    cout << result << '\n';
}