#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

typedef long long ll;

 // 重点为dis数组，记为指定结点到任意结点的最短路。
int n, m, k, dis[45], tmp[45];

vector<int> e[45];
bool vis[45];
queue<int> q;

void spfa(int s){
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    q.push(s);
    dis[s] = 0;
    vis[s] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        vis[cur] = 0;
        for(int i = 0; i < e[cur].size(); i++){
            if(dis[cur] + 1 < dis[e[cur][i]]){
                dis[e[cur][i]] = dis[cur] + 1;
                if(!vis[e[cur][i]]){
                    q.push(e[cur][i]);
                    vis[e[cur][i]] = 1;
                } 
            }
        }
    }
}



int main(){
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    cin >> k;
    while(k--){
        scanf("%d%d", &a, &b);
        spfa(a);
        memcpy(tmp, dis, sizeof(dis));
        spfa(b);
        for(int i = 1; i <= n; i++)
            if(dis[i] + tmp[i] == tmp[b]) printf("%d ", i);
        printf("\n");
    }
    return 0;
}