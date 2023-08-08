#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int next(int x){
	return x + x % 10;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<int> a(n);
		bool flag = false;
		for(int& x : a){
			cin >> x;
			if(x % 5 == 0){
				flag = 1;
				x = next(x);
			}
		}
		if(flag){
			cout << (*min_element(a.begin(), a.end()) == *max_element(a.begin(), a.end()) ? "YES" : "NO") << endl;
		}else{
			bool flag2 = false, flag12 = false;
			for(int x : a){
				while(x % 10 != 4){
					x = next(x);
				}
				if(x % 20 == 4)
					flag2 = true;
				else
					flag12 = true;
			}
			cout << ((flag2 & flag12) ? "NO": "YES") << endl;
		}
	}
	return 0;
}
