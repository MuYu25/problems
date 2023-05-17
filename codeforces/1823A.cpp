#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
 	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n, k;
		cin >> n >> k;
		int index = -1;
		for(int i = 0; i <= n; ++i){
			if(i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2 == k){
				index = i;	
			}
		}
		
		if(index == -1){
			cout << "NO" << endl;
		}else{
			cout << "YES" << endl;
			for(int i = 0; i < n; ++i){
				if(i < index)
					cout << "1 ";
				else
					cout << "-1 ";
			}
			cout << endl;
		}
	}
	return 0;
}
