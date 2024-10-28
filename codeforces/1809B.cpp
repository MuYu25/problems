#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int main(){
	int T;
	cin >> T;
	while(T--){
		ll n;
		cin >> n;
		ll l = 0L;
		ll r = 1e9L;
		while(r >= l){
			ll mid = (l + r) / 2;
			if(mid * mid >= n)
				r = mid - 1;
			else
				l = mid + 1;	
		}
		printf("%d\n", r);
	}
}
