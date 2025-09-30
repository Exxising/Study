// 2022 01 25

#include <iostream>
#include <cmath>
using namespace std;
char arr[1023][2045];

void star(int x, int y, int n, int t){
  int h = pow(2, n)-1;
  int w = (h*2)-1;

  if(n !=0){
    if(n%2==0){
      for(int i=x, l=y, r=y; i>x-h; i--, l--, r++){
        arr[i][l]='*';
        arr[i][r]='*';
        if(i-1==x-h)
          for(int j=y-(w/2); j<y+(w/2)+1; j++) arr[i][j] = '*';
      }
      t -= pow(2, n-1);
      star(x-h+1, y, n-1, t);
    } else {
      for(int i=x+1, l=y, r=y; i<=h+x; i++, l--, r++){
        arr[i][l]='*';
        arr[i][r]='*';
        if(i==h+x){
          for(int j=y-(w/2); j<y+(w/2)+1; j++) arr[i][j]='*';
        }
      }
      star(t, y, n-1, t);
    }
  } else {
    return;
  }
}

int main(){
  int n;
  cin >> n;

  int height = pow(2, n)-1;
  int width = (height*2)-1;

  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      arr[i][j] = ' ';
    }
  }

  if(n%2==0){
    star(height-1, width/2, n, height-1);
    for(int i=height-1; i>=0; i--){
      for(int j=width-1; j>width-1-i; j--){
        arr[i][j]= 0;
      }
    }
  } else {
    star(-1, width/2, n, height-2);
    for(int i=0; i<height; i++){
      for(int j=(width/2)+1+i; j<width; j++){
        arr[i][j] = 0;
      }
    }
  }

  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      if(arr[i][j]==0) continue;
      else cout << arr[i][j];
    }
    cout << '\n';
  }

  return 0;
}