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

// sum_segment_tree
class segmentTree{
private:
    struct segment_tree{
        int l, r;
        int val;
    };
    vector<segment_tree> t; 
public:
    segmentTree(int n) : t(n << 2) {
        build(1, 1, n);
    }

    void push_up(int p){
        t[p].val = t[p << 1].val + t[p << 1 | 1].val;
    }
    
    void build(int p, int l, int r){
        t[p].l = l;
        t[p].r = r;
        if(l == r){
            t[p].val = 0;
            return ;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        push_up(p);
    }

    void modify(int p, int l, int r, int val){
        if(t[p].l == t[p].r){
            t[p].val += val;
            return ;
        }    
        int mid = (t[p].l + t[p].r) >> 1;
        if(l <= mid) modify(p << 1, l, r, val);
        if(mid < r) modify(p << 1 | 1, l, r, val);
        push_up(p);
    }

    void modify(int p, int x, int val){
        if(t[p].l == t[p].r){
            t[p].val += val;
            return ;
        }
        int mid = (t[p].l + t[p].r) >> 1;
        if(x <= mid) modify(p << 1, x, val);
        else modify(p << 1 | 1, x, val);
        push_up(p);
    }

    int query(int p, int l, int r){
        if(r < l){
            return 0;
        }
        if(l <= t[p].l && t[p].r <= r){
            return t[p].val;
        }
        int mid = (t[p].l + t[p].r) >> 1, res = 0;
        if(l <= mid) res += query(p << 1, l, r);
        if(mid < r) res += query(p << 1 | 1, l, r);
        return res;
    }
    
};

void solve(){
    //	segmentTree seg_t(n);
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
