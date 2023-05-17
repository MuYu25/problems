#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
int a[MAXN];
struct node {
    int l, r;
    int sum;
}tr[MAXN << 2];


void build(int u, int l, int r) {
    if (l == r) {
        tr[u] = {l, r, a[l]};
        return;
    }
    tr[u] = {l, r};
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void modify(int u, int x, int c) {
    if (tr[u].l == x && tr[u].r == x) {
        tr[u].sum += c;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid) modify(u << 1, x, c);
    else modify(u << 1 | 1, x, c);
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    int mid = tr[u].l + tr[u].r >> 1, res = 0;
    if (l <= mid) res += query(u << 1, l, r);
    if (r > mid) res += query(u << 1 | 1, l, r);
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (m--) {
        int k, x, y;
        cin >> k >> x >> y;
        if (k == 1) modify(1, x, y);
        else cout << query(1, x, y) << endl;
    }
    return 0;
}
