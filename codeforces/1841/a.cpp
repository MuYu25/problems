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
		if(n > 4){
			cout << "Alice" << '\n';
		}else{
			cout << "Bob" << '\n';
		}
	}

	return 0;
}