// 2023 05 22

#include <iostream>
#include <math.h>
typedef long long ll;
using namespace std;

class SegTree{
private:
    ll* nodes;
    ll* arr;

    ll init(int idx, int start, int end){
        if(start == end) nodes[idx] = arr[start];
        else nodes[idx] =
                init(2*idx + 1, start, (start+end)/2) +
                init(2*idx + 2, (start+end)/2+1, end);
        
        return nodes[idx];
    }

public:
    SegTree(int n, ll* ar){
        int height = (int)ceil(log2(n));
        int size = 1 << (height+1);
        nodes = new ll[size];

        this->arr = ar;
        init(0, 0, n-1);
    }

    ~SegTree(){
        delete []nodes;
    }

    ll getSegTreeSum(int idx, int start, int end, int left, int right){
        if(left > end || right < start) return 0;
        else if(left <= start && right >= end) return nodes[idx];
        else {
            int mid = (start + end) / 2;
            return  getSegTreeSum(2 * idx + 1, start, mid, left, right) +
                    getSegTreeSum(2 * idx + 2, mid+1, end, left, right); 
        }
    }

    void update(int changeIdx, ll diff, int idx, int start, int end){
        if(changeIdx < start || changeIdx > end) return;
        
        nodes[idx] += diff;

        if(start != end){
            int mid = (start+end)/2;
            update(changeIdx, diff, 2 * idx + 1, start, mid);
            update(changeIdx, diff, 2 * idx + 2, mid+1, end);
        } 
    }
};

int main(){
    ll arr[1000001];
    int n, m, k;
    cin >> n >> m >> k;

    int cnt = m + k;
    for(int i=0; i<n; i++) cin >> arr[i];

    SegTree seg(n, arr);

    while(cnt--){
        ll a, b;
        cin >> a >> b;
        if(a == 1){
            ll c;
            cin >> c;
            ll diff = c - arr[b-1];
            arr[b-1] = c;

            seg.update(b-1, diff, 0, 0, n-1);
        } else if(a==2){
            ll c;
            cin >> c;
            cout << seg.getSegTreeSum(0, 0, n-1, b-1, c-1) << '\n';
        }
    }
}