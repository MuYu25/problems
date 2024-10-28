#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb(e) push_back(e)
#define eb(e) emplace_back(e)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pii pair<int, int>

bool cmp(vector<ll>& a, vector<ll>& b){
	return a[0] * a[0] * a[1] + a[0] * a[2] + a[3] > b[0] * b[0] * b[1] + b[0] * b[2] + b[3];
}

void solve(){
	int n, m;
	cin >> n >> m;
	priority_queue<vector<ll>, vector<vector<ll>>, decltype(&cmp)> pq(cmp);
	for(int i = 0; i < n; ++i){
		vector<ll> c(4);
		cin >> c[1] >> c[2] >> c[3];
		c[0] = 1;
		pq.push(c);
	}
	while(m--){
		auto a = pq.top();
		pq.pop();
		ll ans = a[0] * a[0] * a[1] + a[0] * a[2] + a[3];
		++a[0];
		pq.push(a);
		cout << ans << ' ';
	}
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
