// 2022 1 28

#include <iostream>
using namespace std;
int arrowH[1000001];

int main(){
  int n;
  cin >> n;
  int height, cnt=0;
  for(int i=0; i<n; i++) {
    cin>>height;
    if(arrowH[height+1]==0){
      arrowH[height]++;
      cnt++;
    } else {
      arrowH[height+1]--;
      arrowH[height]++;
    }
  }

  cout << cnt;
  return 0;
}