#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

// 斐波那契数列矩阵,以及它的矩阵乘法
struct Matrix{
	int a[3][3];

	Matrix() { memset(a, 0, sizeof a); }

	Matrix operator * (const Matrix &b) const {
		Matrix res;
		for(int i = 1; i <= 2; ++i)
			for(int j = 1; j <= 2; ++j)
				for(int k = 1; k <= 2; ++k)
					// 不是使用 += 是为了防止爆 int
					res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % mod;
		return res;
	}
}ans, base;

void init(){
	base.a[1][1] = base.a[1][2] = base.a[2][1] = 1; 
	ans.a[1][1] = ans.a[1][2] = 1;
}

void qpow(int b){
	while(b){
		if(b & 1) ans = ans * base;
		base = base * base;
		b >>= 1;
	}
}

int n;

void solve(){
	cin >> n;
	if(n <= 2){
		puts("1");
		return ;
	}
	init();
	qpow(n - 1);
	cout << ans.a[1][2] % mod << '\n';
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	// cin >> T;
	T = 1;
	while(T--){
		solve();
	}
	return 0;
}