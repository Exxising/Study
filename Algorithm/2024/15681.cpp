// 2024 6 7

#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100001];
bool check[100001];
int memorize[100001];

int solution(int start) {
  if (memorize[start] != 0) return memorize[start];
  int ans = 1;
  check[start] = true;
  for (int i = 0; i < v[start].size(); i++) {
    int next = v[start][i];
    if (check[next]) continue;
    ans += solution(next);
  }
  memorize[start] = ans;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, r, q, root, sub;
  cin >> n >> r >> q;

  for (int i = 1; i < n; i++) {
    cin >> root >> sub;
    v[root].push_back(sub);
    v[sub].push_back(root);
  }
  memorize[r] = solution(r);
  while (q--) {
    int t;
    cin >> t;
    cout << memorize[t] << '\n';
  }
}