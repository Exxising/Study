// 2023 05 26

#include <iostream>
#include <math.h>
#define LONG_MAX 9223372036854775807
typedef long long ll;
using namespace std;
ll        arr[100001];
ll*       node;
ll*       nodeMin;

ll initMax(int idx, int start, int end){
    if(start == end) return node[idx] = arr[start];
    int mid = (start + end) / 2;
    return node[idx] = max(initMax(2*idx+1, start, mid), initMax(2*idx+2, mid+1, end));
}

ll resultMax(int idx, int start, int end, int left, int right){
    if(right < start || end < left) return 0;
    else if(left <= start && end <= right) return node[idx];
    else{
        int mid = (start + end) / 2;
        return max(resultMax(2 * idx + 1, start, mid, left, right), resultMax(2 * idx + 2, mid+1, end, left, right));
    }
}

ll initMin(int idx, int start, int end){
    if(start == end) return nodeMin[idx] = arr[start];
    int mid = (start + end) / 2;
    return nodeMin[idx] = min(initMin(2*idx+1, start, mid), initMin(2*idx+2, mid+1, end));
}

ll resultMin(int idx, int start, int end, int left, int right){
    if(right < start || end < left) return LONG_MAX;
    else if(left <= start && end <= right) return nodeMin[idx];
    else{
        int mid = (start + end) / 2;
        return min(resultMin(2 * idx + 1, start, mid, left, right), resultMin(2 * idx + 2, mid+1, end, left, right));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++) cin >> arr[i];

    int height = (int)ceil(log2(n));
    int arrSize = 1 << (height+1);
    node = new ll[arrSize];
    nodeMin = new ll[arrSize];

    initMax(0, 0, n-1);
    initMin(0, 0, n-1);

    while(m--){
        int a, b;
        cin >> a >> b;
        cout << resultMin(0, 0, n-1, a-1, b-1) << ' ' << resultMax(0, 0, n-1, a-1, b-1) << '\n';
    }

    return 0;
}