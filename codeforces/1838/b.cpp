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
		vector<int> a(n + 1);
		for(int i = 0; i < n; ++i){
            int x;
			cin >> x;
            a[x] = i + 1;
	    }
        vector<int> q{a[1], a[2], a[n]};
        sort(q.begin(), q.end());
        cout << q[1] << ' ' << a[n] << "\n";
	}

	return 0;
}
