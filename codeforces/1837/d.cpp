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
		string s;
		cin >> s;
		stack<int> st;
		vector<int> ans(n);
		int cnt = 0;
		for(int i = 0; i < s.length(); ++i){
			if(s[i] == '('){
				if(!st.empty() && s[st.top()] == ')'){
					ans[i] = 2;
					ans[st.top()] = 2;
					st.pop();
					cnt |= 1;
					continue;
				}
			}else{
				if(!st.empty() && s[st.top()] == '('){
					ans[i] = 1;
					ans[st.top()] = 1;
					st.pop();
					cnt |= 2;
					continue;
				}
			}
			st.push(i);
		}
		if(st.size() != 0) cout << -1 << "\n";
		else{
			cout << (cnt == 3 ? 2 : 1) << "\n";
			for(int x : ans){
				if(cnt != 3 && x == 2){
					cout << 1 << " ";
				}else{
					cout << x << " ";
				}
			}
			cout << "\n";
		}
	}

	return 0;
}