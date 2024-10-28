#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<vector<ll>> f(N + 5, vector<ll>(M + 5, -1e18)), rf(N + 5, vector<ll> (M + 5, -1e18));
    vector<vector<ll>> a(N + 5, vector<ll> (M + 5));
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            cin >> a[i][j];
    
    f[0][1] = 0; f[1][0] = 0;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            f[i][j] = a[i][j] + max(f[i-1][j], f[i][j-1]);
        }
    }
    
    rf[N + 1][M] = 0; rf[N][M + 1] = 0;
    for(int i = N; i >= 1; --i){
        for(int j = M; j >= 1; --j){
            rf[i][j] = a[i][j] + max(rf[i + 1][j], rf[i][j + 1]);
        }
    }
    
    int T;
    cin >> T;
    while(T--){
        int k;
        cin >> k;
        ll ans = f[N][M];
        ll mx = -1e18, rmx = -1e18;
        vector<pair<int, int>> s(k);
        for(int i = 0; i < k; ++i){
            cin >> s[i].first >> s[i].second;
        }
        for(int i = 0; i < k; ++i){
            for(int j = 0; j < k; ++j){
                if(i == j) continue;
                int x1 = s[i].first, y1=s[i].second;
                int x2 = s[j].first, y2 = s[j].second;
                ans = max(ans, f[x1][y1] + rf[x2][y2]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}