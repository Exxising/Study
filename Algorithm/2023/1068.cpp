// 2023 03 23

#include <iostream>
#include <vector> 
using namespace std;

vector<int> v[51];
int n, k, leafCount=0, root;

int dfs(int node){
	if(node == k) return -1;

	if(v[node].size() == 0) {
		leafCount++;
		return 0;
	}
	for(int i=0; i<v[node].size(); i++){
		int temp = dfs(v[node][i]);
		if(temp == -1 && v[node].size() == 1){
			leafCount++;
		}
	}
	return 0;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		int temp;
		cin >> temp;
		if(temp == -1) root = i;
		else v[temp].push_back(i);
	}
	cin >> k;
	dfs(root);
	cout << leafCount;
}