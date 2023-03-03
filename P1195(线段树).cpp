#include<bits/stdc++.h>

using namespace std;
struct relation{
    int s, e, w;
}a[10010];

int f[1010];

bool judge(relation a, relation b){
    return a.w < b.w;
}

int find(int a){
    if(f[a] != a) f[a] = find(f[a]);
    return f[a];
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) f[i] = i;
    for(int i = 1; i <= m; i++){
        cin >> a[i].s >> a[i].e >> a[i].w;
    }
    sort(a+1, a+1+m, judge);
    int cnt = 0, sum = 0;
    for(int i = 1; i <= m; i++){
        if(find(a[i].s) != find(a[i].e)){
            f[find(a[i].s)] = find(a[i].e);
            sum += a[i].w;
            cnt++;
        }
        if(cnt >= n-k){
            cout << sum << endl;
            return 0;
        }
    }
    cout << "No Answer" << endl;
    return 0;
}