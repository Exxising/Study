// 2023 06 05
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define MAX 32001
using namespace std;
vector<int> v[MAX];
int n, m;
int inDegree[MAX];

void topological(){
    int result[MAX];
    queue<int> q;

    for(int i=1; i<=n; i++){
        if(inDegree[i] == 0) q.push(i);
    }

    for(int i=1; i<=n; i++){
        int x = q.front();
        q.pop();
        result[i] = x;
        for(int j=0; j<v[x].size(); j++){
            int y = v[x][j];
            if(--inDegree[y] == 0) q.push(y);
        }
    }
    for(int i=1; i<=n; i++){
        cout << result[i] << " ";
    }
    cout << '\n';
}

int main(){
    memset(inDegree, 0, sizeof(inDegree));
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int t1, t2;
        cin >> t1 >> t2;
        v[t1].push_back(t2);
        inDegree[t2] += 1;
    }

    topological();
}