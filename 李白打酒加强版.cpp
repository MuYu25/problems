#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;
int n, m;

int main()
{
  // 请在此输入您的代码
  cin >> n >> m;
  vector<vector<vector<int>>> f(n + 1, vector<vector<int>> (m + 1, vector<int> (m + 1, 0)));
  // int f[n+1][m+1][m+1];
  f[0][0][2] = 1;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      for(int k = 0; k <= m; ++k){
        if(2 * k <= m){
          f[i+1][j][2 * k] += f[i][j][k];
          f[i+1][j][2 * k] %= mod;
        }
        if(k - 1 >= 0){
          f[i][j+1][k-1] += f[i][j][k];
          f[i][j+1][k-1] %= mod;
        }
      }
    }
  }

  for(int i = 0; i <= n; ++i)
    for(int j = 0; j <= m; ++j)
        for(int k = 0; k <= m; ++k)
          printf("%d %d %d %d \n", i, j, k, f[i][j][k]);

  
  cout << f[n][m][0] << endl;
  return 0;
}