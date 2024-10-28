/*
题目大致意思，每个月可获得x的点数（下次才可用），只能正序走a，每次可花费a[i]得一个幸福点。题目求最大的幸福点为多少。

思路：
肯定得比较两个方案选哪个，但是怎么比较，才是问题。sum还是累加，若当前sum-（之前已经用掉的花费）> 当前a[i],则可直接拿。
若之前有花费比当前花费的比这次还大，那么则可以替换之前已经选择的a[i],因为每个a[i]提供的贡献值都一样，所以随意替换，之前拿过且花费比当前a[i]还大的花费。
优先队列
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb(e) push_back(e)
#define eb(e) emplace_back(e)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pii pair<int, int>
#define x first
#define y second


void solve(){
	ll n, x;
	cin >> n >> x;
	vector<int> a(n);
	for(auto& x : a){
		cin >> x;
	}
	ll sum = 0;
	priority_queue<ll> q;
	for(auto i : a){
		if(sum >= i){
			q.push(i);
			sum -= i;
		}else if(!q.empty() && q.top() > i){
			sum += q.top() - i;
			q.pop();
			q.push(i);
		}
		sum += x;
	}
	cout << q.size() << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr); // 交互题，要注释掉这个
	int TT;
	// TT = 1;
	cin >> TT;
	while(TT--){
		solve();
	}
	return 0;
}
