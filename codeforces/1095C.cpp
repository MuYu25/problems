#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	int a[k];
	// memset(a, 1, sizeof(a));
	for(int i = 0; i < k; ++i)
		a[i] = 1;
	// 现在n代表还需要分配多少次才能达到要求
	// 因为每次分配只增加一个数字
	n -= k;
	for(int i = 0; i < k; ++i){
		for( ; a[i] <= n; a[i] <<= 1)
			n -= a[i];
		if(n == 0){
			printf("YES\n");
			for(auto x : a)
				printf("%d ", x);
			return 0;
		}
	}
	printf("NO");
	return 0;
}
