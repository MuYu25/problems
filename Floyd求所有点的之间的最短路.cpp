#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int INF = 1e6 + 5;

typedef long long ll;
 
// 连接矩阵存图
int n, m, k, dis[45], tmp[45], matrix[45][45];

vector<int> e[45];
bool vis[45];
queue<int> q;

void floyd(){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            if(matrix[i][k] != INF)
            for(int j = 1; j <= n; j++)
                if(matrix[i][j] > matrix[i][k] + matrix[k][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
}

int main(){
    scanf("%d%d", &n, &m);
    int a, b;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            if(i == j){
                matrix[i][j] = 0;
                continue;
            }
            matrix[i][j] = INF;
        }
            
    
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }
    floyd();
    cin >> k;
    while(k--){
        scanf("%d%d", &a, &b);
        for(int i = 1; i <= n; i++){
            if(matrix[a][i] + matrix[i][b] == matrix[a][b]) printf("%d ", i);
        }
        printf("\n");
        
    }
    return 0;
}