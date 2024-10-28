#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 5;
int spf[N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	iota(spf, spf + N, 0);
	for(int i = 2; i < N; ++i){
		if(spf[i] == i){
			for(int j = i * 2; j < N; j += i){
				spf[j] = min(spf[j], i);
			}
		}
	}
	int T;
	cin >> T;
	while(T--){
		int a, b;
		cin >> a >> b;
		cout << (a == 1 || spf[a] > b ? "YES" : "NO") << endl;
	}
	return 0;
}
