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
		if(n % k == 0){
			for(int i = n; i > 0; --i){
				if(i % k != 0 && (n - i) % k != 0){
					cout << 2 << "\n";
					cout << i << " " << n - i << "\n";
					break;
				}
			}
		}else{
			cout << 1 << "\n";
			cout << n << "\n";
		}
	}
	return 0;
}
