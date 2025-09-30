// 2024 06 07

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define MAXN 701
using namespace std;
int capacity[MAXN][MAXN], flow[MAXN][MAXN];

int MaximumFlow(int start, int end) {
  int ans = 0;

  while (1) {
    queue<int> q;
    vector<int> previous(MAXN, -1);
    previous[start] = start;
    q.push(start);

    while (!q.empty() && previous[end] == -1) {
      int current = q.front();
      q.pop();

      for (int next = 0; next < MAXN; ++next) {
        if (capacity[current][next] - flow[current][next] > 0 &&
            previous[next] == -1) {
          q.push(next);
          previous[next] = current;
        }
      }
    }

    if (previous[end] == -1)
      break;

    int amount = 1e9;
    for (int p = end; p != start; p = previous[p]) {
      amount = min(amount, capacity[previous[p]][p] - flow[previous[p]][p]);
    }

    for (int p = end; p != start; p = previous[p]) {
      flow[previous[p]][p] += amount;
      flow[p][previous[p]] -= amount;
    }

    ans += amount;
  }

  return ans;
}

int main() {
  memset(capacity, 0, sizeof(capacity));
  memset(flow, 0, sizeof(flow));

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char start, end;
    int value;
    cin >> start >> end >> value;
    capacity[start - 'A'][end - 'A'] += value;
    capacity[end - 'A'][start - 'A'] += value;
  }

  cout << MaximumFlow(0, 'Z'-'A') << '\n';
}