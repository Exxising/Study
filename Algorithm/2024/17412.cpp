// 2024 06 07

#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#define MAXN 401
using namespace std;
int capacity[MAXN][MAXN], flow[MAXN][MAXN];

int MaximumFlow(int start, int end) {
  int ans = 0;
  while (1) {
    queue<int> q;
    vector<int> prev(MAXN, -1);
    prev[start] = start;
    q.push(start);

    while (!q.empty() && prev[end] == -1) {
      int current = q.front();
      q.pop();

      for (int next = 1; next < MAXN; next++) {
        if (capacity[current][next] - flow[current][next] > 0 &&
            prev[next] == -1) {
          prev[next] = current;
          q.push(next);
        }
      }
    }
    if (prev[end] == -1)
      break;

    for (int p = end; p != start; p = prev[p]) {
      flow[prev[p]][p] += 1;
      flow[p][prev[p]] -= 1;
    }

    ans += 1;
  }
  return ans;
}

int main() {
  memset(capacity, 0, sizeof(capacity));
  memset(flow, 0, sizeof(flow));

  int n, p;
  cin >> n >> p;

  for (int i = 0; i < p; i++) {
    int s, e;
    cin >> s >> e;
    capacity[s][e] = 1;
  }

  cout << MaximumFlow(1, 2) << '\n';
}