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
		vector<int> a(n);
		int one = 0, two = 0;
		for(int& x: a){
			cin >> x;
			if(x % 2 == 0)
				++two;
			else
				++one;
		}
		
	}
	return 0;
}
