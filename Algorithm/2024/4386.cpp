// 2024 05 16

#include <cmath>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;

vector<pair<double, double>> coord;
vector<pair<int, double>> node[101];
bool visited[101]{
    0,
};

double calculateDistance(double x1, double y1, double x2, double y2) {
  double dx = pow(x2 - x1, 2);
  double dy = pow(y2 - y1, 2);
  return sqrt(dx + dy);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  memset(visited, false, sizeof(visited));
  double ans = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;
    coord.push_back(make_pair(x, y));
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double x2 = coord[j].first, y2 = coord[j].second;
      double dist = calculateDistance(coord[i].first, coord[i].second, x2, y2);

      node[i].push_back({j, dist});
      node[j].push_back({i, dist});
    }
  }

  priority_queue<pair<double, int>> pq;
  for (int i = 0; i < node[0].size(); i++) {
    double cost = node[0][i].second;
    int next = node[0][i].first;

    pq.push({-cost, next});
  }

  visited[0] = true;

  while (!pq.empty()) {
    double cost = -pq.top().first;
    int current = pq.top().second;
    pq.pop();

    if (visited[current]) continue;
    visited[current] = true;
    ans += cost;

    for (int i = 0; i < node[current].size(); i++) {
      int next = node[current][i].first;
      double nextCost = node[current][i].second;
      if (!visited[next]) {
        pq.push({-nextCost, next});
      }
    }
  }
  cout << fixed;
  cout.precision(2);
  cout << ans << '\n';
}
