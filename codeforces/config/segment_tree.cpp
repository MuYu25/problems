#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb(e) push_back(e)
#define eb(e) emplace_back(e)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pii pair<int, int>
#define x first
#define y second

const int N = 2e5 + 5;
int n, q;
int a[N];

class SegmentTree{
private:
	struct segment_tree{
		int l, r;
		int max1, max2, cnt1, cnt2;
	}t[N << 2];

public:
	
	segment_tree merge(segment_tree l, segment_tree r){
		segment_tree ans = {l.l, r.r, 0, 0, 0, 0};
		ans.max1 = max(l.max1, r.max1);
		if(l.max1 > r.max1) ans.cnt1 = l.cnt1;
		else if(l.max1 < r.max1) ans.cnt1 = r.cnt1;
		else ans.cnt1 = l.cnt1 + r.cnt1;
		map<int, int> m;
		m[l.max1] += l.cnt1;
		m[r.max1] += r.cnt1;
		m[l.max2] += l.cnt2;
		m[r.max2] += r.cnt2;
		auto it = m.lower_bound(ans.max1);
		it--;
		ans.max2 = it->first;
		if(it->first == 0) ans.cnt2 = 0;
		else ans.cnt2 = m[it->first];
		return ans;
	}
	
	void push_up(int p){
		t[p] = merge(t[p << 1], t[p << 1 | 1]);
	}
	
	void build(int p, int l, int r){
		t[p].l = l;
		t[p].r = r;
		if(l == r){
			t[p].max1 = a[l];
			t[p].cnt1 = 1;
			t[p].max2 = 0;
			t[p].cnt2 = 0;
			return ;
		}
		int mid = (l + r) >> 1;
		build(p << 1, l, mid);
		build(p << 1 | 1, mid + 1, r);
		push_up(p);
	}

	void modify(int p, int x, int k){
		if(t[p].l == t[p].r){
			t[p].max1 = k;
			t[p].cnt1 = 1;
			return ;
		}
		int mid = (t[p].l + t[p].r) >> 1;
		if(x <= mid) modify(p << 1, x, k);
		else modify(p << 1 | 1, x, k);
		push_up(p);
	}
	
	segment_tree query(int p, int l, int r){
		if(l <= t[p].l && r >= t[p].r) return t[p];
		segment_tree a, b;
		a = b = {0, 0, 0, 0, 0, 0};
		int mid = (t[p].l  + t[p].r) >> 1;
		if(l <= mid) a = query(p << 1, l, r);
		if(mid < r) b = query(p << 1 | 1, l, r);
		if(a.l && b.l)return merge(a, b);
		else if(a.l) return a;
		else if(b.l) return b;
		else return {0, 0, 0, 0, 0, 0};
	}
} t;

void solve(){
	// t.build(1, 1, n);
	// t.modify(1, index, values);
	// t.query(1, left, right)
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr); // 交互题，要注释掉这个
	int TT;
	// TT = 1;
	cin >> TT;
	while(TT--){
		solve();
	}
	return 0;
}
