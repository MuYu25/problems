#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f;

int main()
{
  // 请在此输入您的代码
  int N, M, K, V;
  cin >> N >> M >> K >> V;
  // 每个结点所需时间
  vector<int> times(M + 2, 0);
  // 0为绿灯持续时间， 1为总时间
  int t[M + 2][2];
  for(int i = 1; i <= M ;i++){
    cin >> times[i];
    times[i] -= times[i - 1];
    cin >> t[i][0];
    cin >> t[i][1];
    t[i][1] += t[i][0];
  }
  // 最后一个红绿灯到公司的举例，假设为绿灯时间占比为 100%
  t[M + 1][0] = t[M + 1][1] = 0;

  times[M + 1] = (N - times[M]) * V;

  for(int i = 1; i <= M + 1; i++)
    times[i] *= V;
  
  vector<int> dp (K, 0);
  for(int i = 1; i <= M + 1; i++){
    int tmp = dp[K - 1];
    for(int j = K - 1; j > 0; j--){
      dp[j] = min(dp[j], dp[j-1] + times[i] + ( (dp[j-1] + times[i]) % t[i][1] <= t[i][0] ? 0 : t[i][1] - (dp[j-1] - times[i]) % t[i][1] ) );
    }
    dp[0] = min(dp[0], dp[K - 1]);
  }
  int ans = INF;
  for(int i = 0; i < K; i++) ans = min(ans, dp[i]);
  cout << ans << endl;
  return 0;
}