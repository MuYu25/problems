#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;
		char a = s[0];
		bool ok = 1;
		for(int i = 1; i < s.length(); ++i)
			ok = ok && a == s[i];
		if(s.length() == 1 || ok)
			cout << -1 << endl;
		else
			cout << s.length() - 1 << endl;
	}	
	return 0;
}
