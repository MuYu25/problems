#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1, 0);
	for(int i = 0; i < n - 1; ++i){
		int x, y, w;
		cin >> x >> y >> w;
		a[x] ^= w;
		a[y] ^= w;
	}
	while(q--){
		int op;
		cin >> op;
		if(op == 1){
			int x, y, w;
			cin >> x >> y >> w;
			a[x] ^= w;
			a[y] ^= w;
		}else{
			int index;
			cin >> index;
			cout << a[index] << endl;
		}
	}
	return 0;
}
