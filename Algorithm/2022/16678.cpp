// 2022 2 3

#include <iostream>
#include <algorithm>
using namespace std;
int a[100001];

int main(){
  int n, idx=1;
  long long cnt=0;
  cin >> n;

  for(int i=0; i<n; i++) cin >> a[i];
  sort(a, a+n);

  for(int i=0; i<n; i++){
    if(a[i] >= idx){
      cnt += a[i] - idx;
      idx++;
    }
  }

  cout << cnt;
  return 0;
}