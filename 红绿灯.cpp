#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f;

int main()
{
  // 请在此输入您的代码
  int n, m, k, v;
  cin >> n >> m >> k >> v;
  // 每个结点所需时间
  vector<int> times(m + 2, 0);
  // 0为绿灯持续时间， 1为总时间
  int t[m + 2][2];
  for(int i = 1; i <= m ;i++){
    cin >> times[i];
    cin >> t[i][0];
    cin >> t[i][1];
  }
  // 最后一个红绿灯到公司的举例，假设为绿灯时间占比为 100%
  t[m + 1][0] = t[m + 1][1] = 1;

  times[m + 1] = n;

  for(int i = m + 1; i > 0; i--)
    times[i] =(times[i] - times[i-1]) * v;
  
  vector<int> dp (k, 0);
  for(int i = 1; i <= m + 1; i++){
    int tmp = dp[k - 1];
    for(int j = k - 1; j > 0; j--){
      dp[j] = min(dp[j], dp[j-1] + times[i] + ( (dp[j-1] + times[i]) % t[i][1] <= t[i][0] ? 0 : t[i][1] - (dp[j-1] - times[i]) % t[i][1] ) );
    }
    dp[0] = min(dp[0], dp[k - 1]);
  }
  int ans = INF;
  for(int i = 0; i < k; i++) ans = min(ans, dp[i]);
  cout << ans << endl;
  return 0;
}