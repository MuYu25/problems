#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX = 1e6;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	// vector<bool> vis(MX + 1, false);
	// for(int i = 2; i <= MX; ++i){
    //     if(!vis[i]){
    //         for(int j = i; j <= MX / i; ++j){
    //             vis[i * j] = true;
    //         }
    //     }
    // }
	while(T--){
		int n;
		cin >> n;
		// vector<int> a, b{1, 2};
		// for(int i = 2; i <= n; ++i){
		// 	if(!vis[i]){
		// 		a.push_back(i);
		// 	}else{
		// 		b.push_back(i);
		// 	}
		// }
		vector<int> ans(n);
		int l = n / 2, r = n / 2 + 1;
		ans[l--] = 1;
		while(l >= 0){
			ans[l] = ans[l + 1] + 2;
			l -= 1;
		}
		ans[r++] = 2;
		while(r < n){
			ans[r] = ans[r - 1] + 2;
			r += 1;
		}
		for(int x : ans){
			cout << x << ' ';
		}
		cout << '\n';
	}
	return 0;
}
