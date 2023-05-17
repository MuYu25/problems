#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i] >> b[i];
	}
	int t;
	cin >> t; 
	vector<int> c(n);
	iota(c.begin(), c.end(), 0);
	sort(c.begin() ,c.end(), [&](const int x,const int y){
		return (b[x] == b[y] ? a[x] < a[y] : b[x] < b[y]);
	});
	// for(int x : c) cout << x << " ";
	int ans = 1, cur_b = b[c[0]];
	for(int i = 1; i < n; ++i){
		if(a[c[i]] >= cur_b){
			++ans;
			cur_b = b[c[i]];
		
		}
	}
	cout << ans << endl;
	return 0;
}
