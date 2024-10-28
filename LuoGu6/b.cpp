#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int len, n;
	cin >> len >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	vector<bool> vis(len, 0);
	set<int> s;
	for(int x : a){
		int tmp = __gcd(x, len);
		if(s.count(tmp)){
			cout << 0 << ' ';
		}else{
			int cnt = 0;
			for(int j = 0; j < len; j += tmp){
				if(!vis[j]){
					vis[j] = 1;
					++cnt;
				}
			}
			cout << cnt << ' ';
		}
		s.insert(tmp);
	}
	return 0;
}