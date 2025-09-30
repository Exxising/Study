// 2025 03 20

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define MAX 1002
using namespace std;

int main()
{
    int T;
    cin >> T;       // amount of testcase
    
    while(T--)
    {
        int N, K, W;
        int degree[MAX];        // 정점 진입차수
        int cost[MAX];          // 건물 설치 시간
        int result[MAX];
        vector<int> vec[MAX];   // 그래프 연결

        cin >> N >> K;  // n = amount of structure, k = amount of rule about build structure

        // input cost of build
        for(int i = 1; i<=N; i++)
        {
            cin >> cost[i];
        }

        for(int i = 1; i<=K; i++)
        {
            int cur, next;
            cin >> cur >> next;
            degree[next]++;
            vec[cur].push_back(next);
        }

        cin >> W;

        queue<int> q;
        for(int i = 1; i<=N; i++)
        {
            if(degree[i] == 0) 
            {
                q.push(i);   // 진입차수 0 삽입
            }
            result[i] = cost[i];
        }

        for(int i = 1; i<=N; i++)
        {
            if(q.empty()) break;
            int current = q.front();
            q.pop();

            for(int j = 0; j<vec[current].size(); j++)
            {
                int next = vec[current][j];
                result[next] = max(result[next], result[current] + cost[next]);

                if(--degree[next] == 0)
                {
                    q.push(next);
                }
            }
        }
        cout << result[W] << '\n';
    }
}