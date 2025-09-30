// 2024 03 08

#include <iostream>
using namespace std;
struct Node{
    Node() {}

    Node(long long int _v, int _i)
        : value(_v)
        , idx(_i)
    { }

    long long int value;
    int idx;

} seg[1<<21];

long long int arr[100001];

Node segInit(int start, int end, int idx){
    if(start == end) {
        seg[idx] = Node(arr[start], start);
        return seg[idx];
    }
    int mid = (start + end) >> 1;
    
    Node left = segInit(start, mid , idx * 2);
    Node right = segInit(mid+1, end, idx*2+1);

    return seg[idx] = ((left.value > right.value) ? right : left);
}

void segUpdate(int start, int end, int node, int idx, long long int value){
    if(start > idx || idx > end) return;
    else if(start == end && start == idx) {
        seg[node] = Node(value, idx);
        return;
    } else {
        int mid = (start + end) >> 1;
        segUpdate(start, mid , node * 2, idx, value);
        segUpdate(mid+1, end, node*2+1, idx, value);

        seg[node] = ((seg[node*2].value > seg[node*2+1].value) ? seg[node*2+1] : seg[node*2]);
        return;
    }
}

void segQuery(){
    cout << seg[1].idx << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m; cin >> n;
    for(int i = 1; i<=n; i++) cin >> arr[i];
    segInit(1, n, 1);

    cin >> m;
    while(m--){
        int q; cin >> q;
        if(q == 1){
            int idx;
            long long int value;
            cin >> idx >> value;
            segUpdate(1, n, 1, idx, value);
        } else if(q == 2){
            segQuery();
        }
    }
}
