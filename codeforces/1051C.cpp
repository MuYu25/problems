#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> count(101, 0);
	int cnt1 = 0, cnt3 = 0; 
	for(int& x : a){
		cin >> x;
		++count[x];
		if(count[x] == 1){
			cnt1 += 1;
		}else if(count[x] == 2){
			cnt1 -= 1;
		}else if(count[x] == 3){
			cnt3 += 1;
		}
	}
	if(cnt1 % 2 == 0){
		cout << "YES" << '\n';
		int sum = cnt1 / 2;
		for(int x : a){
			if(count[x] == 1){
				if(sum > 0){
					cout << 'A';
					sum -= 1;
				}else{
					cout << 'B';
				}
			}else{
				cout << 'A';
			}
		}
	}else{
		if(cnt3 == 0){
			cout << "NO" << '\n';
		}else{
			cout << "YES" << '\n';
			int sum = cnt1 / 2 + 1;
			bool ok = false;
			for(int x : a){
				if(count[x] == 1){
					if(sum > 0){
						cout << 'A';
						sum -= 1;
					}else{
						cout << 'B';	
					}
				}else if(count[x] >= 3 && !ok){
					cout << 'B';		
					ok = true;
				}else{
					cout << 'A';
				}
			}
		}
	}

	return 0;
}