#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n + 1, 0);
	vector<pair<ll, int>> pre(n + 1, {0, 0});
	for(int i = 0; i < n; ++i){
		cin >> a[i + 1];
		a[i + 1] += a[i];
	if(a[i + 1] > pre[i].first){
			pre[i + 1] = {a[i + 1], i + 1};
		}else{
			pre[i + 1] = pre[i];
		}
	}
	ll ans = -1e18;
	int p, q, r;
	int suf = a[n], sufI = n;
	for(int i = n; i >= 0; --i){
		if(a[i] > suf){
			suf = a[i];
			sufI = i;
		}
		ll t = pre[i].first - a[i] + suf;
		if(t > ans){
			ans = t;
			p = pre[i].second;
			q = i;
			r = sufI;
		}
	}
	printf("%d %d %d\n", p, q, r);
	return 0;
}
