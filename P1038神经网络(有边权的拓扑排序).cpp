#include<bits/stdc++.h>

using namespace std;

const int N = 105;

int n, m, c[N], in[N], head[N], cnt;
bool vis[N], out[N];

// 链式前向星
struct node{
	// e[i].next 指向下一个出发点为i的路径。
	int to, weight, next;
}e[2 * N];

void add(int x, int y, int val){
	++cnt;
	e[cnt].to = y;
	e[cnt].weight = val;
	e[cnt].next = head[x];
	head[x] = cnt;
}


int main(){
	cin >> n >> m;
	queue<int> q;
	int u;
	for(int i = 1; i <= n; i++){
		cin >> c[i] >> u;
		if(c[i]){
			q.push(i);
			vis[i] = 1;
		}else c[i] -= u;
	}
	int x, y, val;
	for(int i = 1; i <= m; i++){
		cin >> x >> y >> val;
		add(x, y, val);
		in[y]++;
		out[x] = true;
	}
	while(!q.empty()){
		int cur = q.front(); q.pop();
		if(c[cur] < 0) continue;
		for(int i = head[cur]; i; i = e[i].next){
			int to = e[i].to;
			--in[to];
			if(vis[to] == 0 && in[to] == 0){
				q.push(to);
				vis[to] = 1;
			}
			c[to] += c[cur] * e[i].weight;
		}	
	}
	bool j = true;
	for(int i = 1; i <= n; i++){
		if(c[i] > 0 && !out[i]){
			cout << i << " " << c[i] << endl;
			j = false;
		}
	}
	if(j) cout << "NULL" << endl;
	
}