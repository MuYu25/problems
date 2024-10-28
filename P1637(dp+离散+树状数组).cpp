#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define lowbit(x) ((x) & (-x))

int len, m, tree[4][30005], arr[30005], s[30005], c[60010];

int val(int x){
    return lower_bound(s+1, s+m+1, x) - s;
}

void add(int x, int val){
    while(x <= len){
        c[x] += val;
        x += lowbit(x);
    }
}

ll query(int x, ll sum = 0){
    for(; x; x -= x & (-x)){
        sum += c[x];
    }
    return sum;
}

int main(){
    cin >> len;
    for(int i = 1; i <= len; i++) cin >> arr[i], s[i] = arr[i];
    sort(s+1, s+len+1);
    int index = 1, cur = -1;
    m = unique(s+1, s+len+1) - (s+1);
    for(int i = 1; i <= len; i++) tree[1][i] = 1, arr[i] = val(arr[i]);
    ll ans = 0;
    for(int i = 2; i <= 3; i++){
        memset(c, 0, sizeof(c));
        for(int j = 1; j <= len; j++){
            tree[i][j] = query(arr[j]-1);
            add(arr[j], tree[i-1][j]);
        }
    }
    for(int i = 1; i <= len; i++) ans += tree[3][i];
    cout << ans << endl;
    return 0;
}