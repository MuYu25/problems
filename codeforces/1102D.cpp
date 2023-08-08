#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> cnt(3, -(n / 3));
	for(auto c : s)
		++cnt[c - '0'];
	for(int i = 0; i < n; ++i){
		int index = s[i] - '0';
		if(cnt[index] <= 0) continue;
		for(int j = 0; j < 2; ++j){
			if(index > j && cnt[j] < 0){
				s[i] = '0' + j;
				--cnt[index];
				++cnt[j];
				break;
			}
		}
	}

	for(int i = n - 1; i >= 0; --i){
		int index = s[i] - '0';
		if(cnt[index] <= 0) continue;
		for(int j = 2; j >= 0; --j){
			if(index < j && cnt[j] < 0){
				s[i] = '0' + j;
				--cnt[index];
				++cnt[j];
				break;
			}
		}	
	}
	cout << s << "\n";
	return 0;
}
