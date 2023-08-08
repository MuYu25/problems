#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n , m;
		cin >> n >> m;
		for(int i = 1; i < n; i += 2){
			for(int j = 1; j <= m; ++j){
				printf("%3d ", j + m * i);
			}
			printf("\n");
		}
		for(int i = 0; i < n; i += 2){
			for(int j = 1; j <= m; ++j){
				printf("%3d ", j + m * i);
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}