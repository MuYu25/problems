#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb(e) push_back(e)
#define eb(e) emplace_back(e)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pii pair<int, int>
#define x first
#define y second


void solve(){
	ll n;
	cin >> n;
	vector<int> a(n);
	for(auto& c : a) cin >> c;
	int mod = 1e9 + 7;
	int mn = *min_element(all(a));
	ll cnt = 0;
	for(auto x : a){
		if(x == mn) cnt++;
		if((x&mn) != mn){
            // 若当前数与最小值&得到的不是最小值，那么任意一个序列中都不可能存在所有的 a_i 都满足(a_0&_a1&..&a_i) = (a_i+1&a_i+2&...a_n)
			cout << "0\n";
			return ;
		}
	}
	ll mask = 1;
    // mask 为中间对最小值没有影响的数的数量，当前也包括mn，除去两边两个固定值，其他地方都快任意安排
    // 故安排中间的方案数为，cnt *= i(1 <= i <= n - 2), 也为(n - 2) * (n - 3) / 2; 但n最小值为2，可能会出现负数的情况，还是逐步累乘
	for(int i = 1; i <= n - 2; ++i) mask = (mask * i) % mod;
    // 此处ans为将最小值安排至角落的方案数，由于同样的两个数，分别不同的放在两个角落，算两种方案数，故不需要 /2;
    // 且，若cnt为1时，也会因为此处的ans计算，最终结果为0
	ll ans = (cnt * (cnt - 1)) % mod;
    // 最后的结果也为两边的方案数*中间的方案数
	cout << (ans * mask) % mod << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr); // 交互题，要注释掉这个
	int TT;
	// TT = 1;
	cin >> TT;
	while(TT--){
		solve();
	}
}
