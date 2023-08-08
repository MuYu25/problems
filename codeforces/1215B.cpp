#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	// 子数组个数,分别求出乘积为负数的子数组个数与乘积为正数的子数组的个数
	// 需要设计一个时间复杂度小于等于 O(nlogn) 的算法
	// 用前缀和统计出前 i 个数中有多少个负数
	// 由于偶数个数的乘积为正数, 所以只需要看前缀和的奇偶性.
	// 一边计算前缀和和 s[i] ,一边计算答案
	// 负数个数 = 与 s[i] 奇偶性不同的前缀和的个数
	// 正数个数 = 与 s[i] 奇偶性相同的前缀和的个数
	vector<int> cnt{1, 0};
	int s = 0;
	ll ans0 = 0, ans1 = 0; 
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		if(x < 0){
			s ^= 1;
		}
		ans0 += cnt[s ^ 1];
		ans1 += cnt[s];
		++cnt[s];
	}
	cout << ans0 << ' ' << ans1 << '\n';
	return 0;
}
