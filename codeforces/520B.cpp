#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	if(n >= m){
		cout << n - m << endl;
		return 0;
	}
	int ans = 0;
	while(m > n){
		if(m % 2 == 0)
			m /= 2;
		else
			++m;
		ans++;
	}
	cout << ans + n - m << endl;
	return 0;
}
