#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	scanf("%d", &n);
	int a[n + 1], ans = 1;
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	a[0] = 1e9 + 5;
	vector<vector<int>> f(n + 1, vector<int>(2, 1));
	f[0][0] = 0;
	f[0][1] = 0;
	for(int i = 2; i <= n; ++i){
		if(a[i] > a[i-1]){
			f[i][0] = f[i-1][0] + 1;
			f[i][1] = f[i-1][1] + 1;
		}
		if(a[i] > a[i-2])
			f[i][1] = max(f[i][1], f[i - 2][0] + 1);
		ans = max(ans, max(f[i][0], f[i][1]));
	}
//	for(auto i : f)
//		printf("%d %d\n", i[0], i[1]);
	printf("%d", ans);
	return 0;
}

