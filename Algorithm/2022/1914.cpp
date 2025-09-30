// 2022 02 03

#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>
using namespace std;

void hanoi(int n, int x, int y, int z){
  if(n==1){
    cout << x << ' ' << z << '\n';
  } else {
    hanoi(n-1, x, z, y);
    cout << x << ' ' << z << '\n';
    hanoi(n-1, y, x, z);
  }
}

int main(){
  int n;
  cin >> n;
  string ans = to_string(pow(2,n));
  int idx=ans.find('.');
  ans = ans.substr(0, idx);
  ans[ans.length()-1] -= 1;
  cout << ans << '\n';
  if(n<=20) hanoi(n, 1, 2, 3);
  
  return 0;
}