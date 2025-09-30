// 2022 11 07

#include <iostream>
using namespace std;
int tree[1001];
int dp[31][2][1001];

int main() {
    int t, w;
    cin >> t >> w;
    for (int i = 1; i <= t; i++) cin >> tree[i];

    for (int i = 0; i <= w; i++) {
        for (int j = 1; j <= t; j++) {
            if (i == 0) { 
                dp[i][0][j] = dp[i][0][j - 1] + (tree[j] == 1);
            } else {
                dp[i][0][j] = max(dp[i][0][j - 1] + (tree[j] == 1), dp[i - 1][1][j - 1] + (tree[j] == 1));
                dp[i][1][j] = max(dp[i][1][j - 1] + (tree[j] == 2), dp[i - 1][0][j - 1] + (tree[j] == 2));
            }
        }
    }
    int result = 0;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j <= w; j++)
            result = max(result, dp[j][i][t]);

    cout << result;
}

