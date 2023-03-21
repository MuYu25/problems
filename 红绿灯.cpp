#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f;

int main(){
  int n, m, k, v;
  // n 为汽车到目的地的总距离
  // m 为红绿灯的数量
  //  k 为能使用氮气的充能时间， 氮气充满后，可使用氮气，直接到达下一个红绿灯
  // v 为速度，不过速度为 1 / v;
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
    int cur = t[i][1] + t[i][0];
    for(int j = k - 1; j > 0; j--){
        int val1 = dp[j-1] + times[i];
        int val2 = dp[j] + times[i];
        val1 = val1 + ((val1 % cur) < t[i][0] ? 0 : cur - val1 % cur);
        val2 = val2 + ((val2 % cur) < t[i][0] ? 0 : cur - val2 % cur);
        dp[j] = min(val1, val2);
    }
    dp[0] = min(dp[0] + times[i] + ((dp[0] + times[i]) % cur < t[i][0] ? 0 : t[i][1] - (dp[0] + times[i]) % cur), tmp);
  }
  // 返回的结果为汽车最短到达目的地的时间
  int ans = INF;
  for(int i = 0; i < k; i++) ans = min(ans, dp[i]);
  cout << ans << endl;
  return 0;
}