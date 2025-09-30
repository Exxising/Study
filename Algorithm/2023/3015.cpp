// 2023 04 14

#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, height;
    long long int answer = 0;
    stack<pair<int, int>> st;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> height;

        // Condition 1. A < B
        while(!st.empty() && height > st.top().first){
            answer += st.top().second;
            st.pop();
        }
        
        if(st.empty()) st.push(make_pair(height, 1));

        else {
        // Condition 2. A = B
            if(st.top().first == height){
                int current = st.top().second;
                answer += current;
                st.pop(); // 기존에 있던 pair 제거
                
                if(!st.empty()) answer += 1;
                
                st.push(make_pair(height, current+1));
            }

        // Conditionn 3. A > B
            else {
                answer += 1;
                st.push(make_pair(height, 1));
            }
        }
    }

    cout << answer << '\n';
    return 0;
}