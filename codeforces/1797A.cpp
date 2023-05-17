#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n, m, x1, y1, x2, y2;
		cin >> m >> n >> x1 >> y1 >> x2 >> y2;
		int ans1 = 4, ans2 = 4;
		if((x1 == 1) || (x1 == m)) --ans1;
		if((x2 == 1) || (x2 == m)) --ans2;
		if((y1 == 1) || (y1 == n)) --ans1;
		if((y2 == 1) || (y2 == n)) --ans2;
		cout << min(ans1, ans2) << endl;
	}
	return 0;
}
