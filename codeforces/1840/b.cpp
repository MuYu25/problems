#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n, k;
		cin >> n >> k;
		if(k > 30){
			cout << n + 1 << "\n";
		}else{
			cout << min(n + 1, 1 << k) << '\n';
		}
	}

	return 0;
}