#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = (ll)1e15 + 7;

int main(){
  int n, m, k, v;
  // n 为汽车到目的地的总距离
  // m 为红绿灯的数量
  //  k 为能使用氮气的充能时间， 氮气充满后，可使用氮气，直接到达下一个红绿灯
  // v 为速度，不过速度为 1 / v;
  cin >> n >> m >> k >> v;
  // 每个结点所需时间
  vector<ll> times(m + 2, 0);
  // 0为绿灯持续时间， 1为红灯持续时间
  ll t[m + 2][2];
  for(int i = 1; i <= m ;i++){
    cin >> times[i];
    cin >> t[i][0];
    cin >> t[i][1];
  }
  
  // 最后一个红绿灯到公司的举例，假设为绿灯时间占比为 100%
  t[m + 1][0] = 1;
  t[m + 1][1] = 0;
  
  times[m + 1] = n;

  vector<vector<ll>> dp(m+2, vector<ll> (k, INF));

  
  // dp[0][0] = 0;
  // // memset(dp[0], 0, sizeof(dp[0]));
  for(int i = 0; i < k; i++) dp[0][i] = 0;

  
  // dp[i][j] 表示的意思为通过第i的红绿灯且充能为j的最短时间
  for(int i = 1; i <= m + 1; i++){
    ll cur = t[i][0] + t[i][1];

    // 使用氮气加速，必须要保证上一个阶段已经达到过了；
    if(dp[i-1][0] != INF){
      dp[i][k-1] = dp[i-1][0];
      ll dt;
      if((dt = dp[i][k-1] % cur) >= t[i][0])
        dp[i][k-1] += cur - dt;
    }

    // 氮气充满的状态可以由氮气充满的前一个状态与氮气充满的状态转移而来
    ll tmp = min(dp[i-1][0], dp[i-1][1]);
    if(tmp != INF){
      dp[i][0] = v * (times[i] - times[i-1]) + tmp;
      ll dt = dp[i][0] % cur;
      // 满足当前情况就需要等待红灯转为绿灯
      if(dt >= t[i][0])
        dp[i][0] += cur - dt;
    }
    

    // 其他时刻直接正常转移即可
    for(int j = 1; j < k-1; j++){
      if(dp[i-1][j+1] != INF){
        dp[i][j] = dp[i-1][j+1] + v * (times[i] - times[i-1]);
        ll dt = dp[i][j] % cur;
        if(dt >= t[i][0])
            dp[i][j] += cur - dt;
        }
    }
  }
  
  // 返回的结果为汽车最短到达目的地的时间
  ll ans = INF;
  for(int i = 0; i < k; i++) ans = min(ans, dp[m+1][i]);
  printf("%lld \n", ans);
  return 0;
}