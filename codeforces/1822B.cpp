#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<ll> a(n);
		for(ll& x : a) cin >> x;
		sort(a.begin(), a.end());
	      	cout << max(a[0] * a[1], a[n-1] * a[n-2]) << endl;	
	}
	return 0;
}
