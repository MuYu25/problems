#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;
		char a = '0';
		for(int i = 0; i < s.length(); ++i){
			if(s[i] == '?'){
				s[i] = a;
			}
			a = s[i];
		}
		cout << s << "\n";
		
	}
	return 0;
}
