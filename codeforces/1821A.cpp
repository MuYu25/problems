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
    		ll ans = 1;
    		if(s[0] == '0') ans = 0;
		else if(s[0] == '?') ans = 9;
    		for(int i = 1; i < s.length(); ++i){
			if(s[i] == '?')
				ans *= 10;
    	} 
    	cout << ans << endl;	

	}
    	return 0;
}
