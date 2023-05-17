#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int main(){
	int n;
	scanf("%d", &n);
	int e[n][n];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &e[i][j]);
		
	ll ans[n];
	for(int i = 0; i < n; ++i){
		scanf("%lld", &ans[i]);
		--ans[i];
	}
	bool vis[n];
	memset(vis, false, sizeof(vis));
	for(int q = n - 1;  q >= 0; --q){
		int k = ans[q];
		vis[k] = 1;
		ans[q] = 0;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
				if(vis[i] && vis[j])
					ans[q] += e[i][j];

			}
		}
	}
	for(auto i : ans){
		printf("%lld ", i);	
	}
	return 0;
}
