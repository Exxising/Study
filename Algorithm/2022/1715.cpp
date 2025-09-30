// 2022 01 30

#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
  int n, t, result=0;
  cin >> n;
  while(n--){
    cin >> t;
    pq.push(t);
  }

  while(pq.size()!=1){
    int a=pq.top();
    pq.pop();
    int b=pq.top();
    pq.pop();
    result += a+b;
    pq.push(a+b);
  }

  cout << result;
  return 0;
}