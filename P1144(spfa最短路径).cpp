#include<bits/stdc++.h>

using namespace std;

const int maxn = 100010, maxm = 200010, INF = 0X7f7f7f7f, MOD = 100003;

vector<int> G[maxn]; int depth[maxn], ans[maxn]; bool vis[maxn];



int main(){
    int n, m;
    cin >> n >> m;
    int x, y;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    queue<int> q;
    dep[1] = 0;
    vis[1] = 1;
    cnt[1] = 1;
    q.push(1);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0; i < G[x].size(); i++){
            int t = G[x][i];
            if(!vis[t]){
                vis[t] = 1;
                dep[t] = dep[x] + 1;
                q.push(t);
            }
            if(dep[t] == dep[x] + 1) cnt[t] = (cnt[t] + cnt[x]) % MOD;
        }
    }
    for(int i = 1; i <= n; i++) cout << cnt[i] << endl;
    return 0;
}