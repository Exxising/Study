// 2022 1 9

#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n, int x, int y, int z){
  if(n==1){
    cout << x << ' ' << z << '\n';
  } else{
    hanoi(n-1, x, z, y);
    cout << x << ' ' << z << '\n';
    hanoi(n-1, y, x, z);
  }
}

int main(){
  int n;
  cin >> n;
  int k = pow(2, n) - 1;
  cout << k << '\n';
  hanoi(n, 1, 2, 3);
}