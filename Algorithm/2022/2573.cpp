// 2022 03 03

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
bool check[301][301];
int arr[301][301];
int tempArr[301][301];
int px[4] = {0, 0, 1, -1};
int py[4] = {1, -1, 0, 0};
int island, year=0;

bool allMelted(int x, int y){
  for(int i=0; i<x; i++){
    for(int j=0; j<y; j++){
      if(arr[i][j]!=0) return false;
    }
  }
  return true;
}

void melting(int x, int y){
  int sea=0;
  for(int i=0; i<4; i++){
    int cx = x+px[i];
    int cy = y+py[i];

    if(arr[cx][cy]==0){
      sea++;
    }
  }
  tempArr[x][y] = arr[x][y]-sea;
  if(tempArr[x][y]<0) tempArr[x][y] = 0;
}

void checkingIslandCount(int x, int y){
  if(check[x][y]) return;
  check[x][y] = true;
  
  for(int i=0; i<4; i++){
    int cx = x+px[i];
    int cy = y+py[i];

    if(arr[cx][cy]>=1 && !check[cx][cy]){
      checkingIslandCount(cx, cy);
    }
  }
}

int main(){
  int n, m, k=2;
  cin >> n >> m;
  memset(arr, 0, sizeof(arr));
  
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      cin >> arr[i][j];

  while(true){
    memset(check, false, sizeof(check));
    memset(tempArr, 0, sizeof(tempArr));
    year++;
    island=0;
    
    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
        if(arr[i][j] > 0)
          melting(i, j);

    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
        arr[i][j] = tempArr[i][j];
    
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(arr[i][j] > 0 && !check[i][j]){
          checkingIslandCount(i, j);
          island++;
        }
      }
    }
    if(island>1) break;
    else if(allMelted(n,m)){
      cout << 0;
      return 0;
    }
  }
  cout << year;
  return 0;
}