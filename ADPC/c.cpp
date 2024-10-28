#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll n;
	cin >> n;
	ll tmp = n;
	int cnt = 0;
	while(tmp){
		++cnt;
		tmp = tmp & (tmp - 1);
	}
	for(ll i = 0; i < (1 << ))

	return 0;
}