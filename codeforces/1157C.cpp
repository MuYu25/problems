#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a){
		cin >> x;
	}
	int pre = 0;
	int l = 0, r = n - 1;
	int ans = 0;
	string s = "";
	while(l <= r && (a[l] > pre || a[r] > pre)){
		bool isR = (a[l] <= pre || a[r] > pre && a[r] < a[l]);
		if(a[l] == a[r]){
			int ll = l + 1;
			while(ll < r && a[ll] > a[ll - 1]){
				++ll;
			}
			int rr = r - 1;
			while(l < rr && a[rr] > a[rr + 1]){
				--rr;
			}
			isR = r - rr > ll - l;
		}
		if(isR){
			++ans;
			pre = a[r--];
			s += 'R';
		}else{
			++ ans;
			pre = a[l++];
			s += 'L';
		}
	}
	cout << ans << '\n';
	cout << s << '\n';
	return 0;
}