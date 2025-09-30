// 2022 04 25
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int scr, sct, n, m, cnt=0;
vector<int> cr;
vector<int> ct;

int main(){
  cin >> scr;
  for(int i=0; i<scr; i++){
    cin >> n;
    cr.push_back(n);
  }

  cin >> sct;
  for(int i=0; i<sct; i++){
    cin >> m;
    ct.push_back(m);
  }
  sort(cr.begin(), cr.end(), greater<int>());
  sort(ct.begin(), ct.end(), greater<int>());

  if(cr[0] < ct[0]){
    cout << -1;
    return 0;
  }

  while(!ct.empty()){
    cnt++;
    for(int i=0; i<cr.size(); i++){
      for(int j=0; j<ct.size(); j++){
        if(cr[i] >= ct[j]){
          ct.erase(ct.begin()+j);
          break;
        }
      }
    }
  }
  cout << cnt;
  return 0;
}
