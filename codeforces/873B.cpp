#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		ll a[n + 1];
		for(int i = 1; i <= n; ++i)
			scanf("%lld", &a[i]);
		sort(a + 1, a + n + 1);
		ll ans = 0;
		if(a[1] * a[2] > ans)
			ans = a[1] * a[2];
		if(a[n] * a[n-1] > ans)
			ans = a[n] * a[n-1];
		printf("%lld\n", ans);	
	}
	return 0;
}
