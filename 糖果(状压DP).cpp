#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n + 1, 0);
    bool vis[m];
    int tmp;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < k; j++){
            cin >> tmp;
            vis[--tmp] = 1;
            arr[i] |= 1 << tmp; 
        }
    }
    for(int i = 0; i < m; i++){
        if(!vis[i]){
            cout << "-1" << endl;
            return 0;
        } 
    }
    
    vector<int> f (1 << m, INF);
    f[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = (1<<m) -1; j >= 0; j--){
            f[j | arr[i]] = min(f[j | arr[i]], f[j] + 1);
        }
    }
    cout << f[(1<<m)-1] << endl;
    return 0;
}
