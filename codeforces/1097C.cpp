#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb(e) push_back(e)
#define eb(e) emplace_back(e)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pii pair<int, int>

void solve(){
    int n;
    cin >> n;
    int ans = 0;
    map<int, int> m;
    for(int i = 0; i < n; ++i){
		string s;
		cin >> s;
		int cnt = 0, mn = 0;
		for(auto x : s){
			if(x == '(') cnt++;
			else cnt--;
			mn = min(cnt, mn);
		}
		if(mn == 0 || mn == cnt){ //重点为判断当前括号是否合法)(为不合法的情况，需要排除.在括号问题中，可以使用当前最小值是否等于当前值和最小值是否等于0来判断一个括号序列是否合法
			if(m[-cnt] > 0){
				m[-cnt]--;
				ans++;
			}else{
				m[cnt]++;
				}
			}
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	T = 1;
	// cin >> T;
	while(T--){
		solve();
	}
}
