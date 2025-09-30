// 2023 06 05

#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#define MAX 1001
using namespace std;
int n, m;
int inDegree[MAX];
vector<int> v[MAX];

void topologySort(){
    int result[MAX];
    queue<int> q;

    for(int i=1; i<=n; i++){
        if(inDegree[i]==0) q.push(i);
    }

    for(int i=1; i<=n; i++){
        if(q.empty()) { cout << "0" << '\n'; return;}
        int x = q.front();
        q.pop();
        result[i] = x;
        for(int j=0; j<v[x].size(); j++){
            int y = v[x][j];
            inDegree[y] -= 1;
            if(inDegree[y] == 0) q.push(y);
        }
    }

    for(int i=1; i<=n; i++){
        cout << result[i] << '\n';
    }
}

int main(){
    memset(inDegree, 0, sizeof(inDegree));
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int tempArr[MAX];
        int k;
        cin >> k;
        for(int j=0; j<k; j++) cin >> tempArr[j];

        for(int l=0; l<k-1; l++){
            v[tempArr[l]].push_back(tempArr[l+1]);
            inDegree[tempArr[l+1]]++;
        }
    }

    topologySort();
}