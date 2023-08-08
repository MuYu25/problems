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
		vector<int> a(n), b;
		for(int& x : a){
			cin >> x;
		}
		int cnt = 0;
		b.push_back(a[0]);
		cout << 1;
		for(int i = 1; i < n; ++i){
			int x = a[i];
			// 使用cnt记录当前处于上升还是下降状态；
			// 当处于上升状态是 cnt 为0, 下降状态是为 1, 因为第一次开始降序时, 元素才会加入队尾
			// 当 cnt == 1 时, 且x >= b.back()的情况, x 是不会加入队尾的
			int new_cnt =  cnt + (b.size() > 0 && b.back() > x);
			if(new_cnt == 0 || (new_cnt == 1 && b[0] >= x)){
				cout << 1;
				b.emplace_back(x);
				cnt = new_cnt;
			}else{
				cout << 0;
			}
		}
		cout << '\n';
	}

	return 0;
}