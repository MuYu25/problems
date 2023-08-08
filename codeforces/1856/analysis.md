# [C To Become Max](https://codeforces.com/contest/1856/problem/C)

## 题面翻译

给定两个正整数 $n$ 和 $k$，以及一个长度为 $n$ 的序列 $a$，你可以进行不超过 $k$ 次如下操作（以下两个步骤合称一次操作）：

- 选择一个 $i$ 满足 $1 \le i < n$，且 $a_i \le a_{i + 1}$。

- 将 $a_i$ 增加 $1$。

求操作完成后，$\max \limits_{i = 1} ^ {n} a_i$ 的最大可以是多少。

多测，共 $t$ 组数据。

对于所有数据，保证 $1 \le t \le 100$，$1 \le n, \sum n \le 1000$，$1 \le k, a_i \le 10 ^ 8$。

# 样例 #1

### 样例输入 #1

```
6
3 4
1 3 3
5 6
1 3 4 5 1
4 13
1 1 3 179
5 3
4 3 2 2 2
5 6
6 5 4 1 5
2 17
3 5
```

### 样例输出 #1

```
4
7
179
5
7
6
```

## 提示

In the first test case, one possible optimal sequence of operations is: $ [\color{red}{1}, 3, 3] \rightarrow [2, \color{red}{3}, 3] \rightarrow [\color{red}{2}, 4, 3] \rightarrow [\color{red}{3}, 4, 3] \rightarrow [4, 4, 3] $ .

In the second test case, one possible optimal sequence of operations is: $ [1, \color{red}{3}, 4, 5, 1] \rightarrow [1, \color{red}{4}, 4, 5, 1] \rightarrow [1, 5, \color{red}{4}, 5, 1] \rightarrow [1, 5, \color{red}{5}, 5, 1] \rightarrow [1, \color{red}{5}, 6, 5, 1] \rightarrow [1, \color{red}{6}, 6, 5, 1] \rightarrow [1, 7, 6, 5, 1] $ .

## 题解解析

首先可看数据范围，　`n < 1000`即表示算法的最大时间限制为$(n^2logn)$，结果是有一个单调性的，我们需要找到花费至多`k`次操作,来使得我们的结果最大化。

到最大化，在结果(称之为res)的数轴上，当res越大时，我们越不能达成，在当res越小时，我们越有可能达成条件。这很明显，就是结果的单调性。知道我们可以二分求答案时，可以试着忘二分上思考答案·。

按照二分答案的思路，我们该怎么知道当前`mid`的结果是不是满足总的操作次数小于`k`次呢？毕竟我们只知道操作次数，很难求最大值。

我们不妨换一个思路，我们假设下标为`i`的数字一定能` >= mid`，我们求操作次数。如果当前操作次数`> k`，那么这就是不可能实现的。同时我们假设，`f(i, y)` 表示下标为`i`的值到达`y`的最小花费。
那么`f(i, y)` 就有以下几种关系：
1. $f(i, y) = 0$, for all $y <= a_i $
2. $f(i, y) = y - a_i + f(i + 1, y - 1)$ for all $1 <= i < n$ and $y > a_i$
3. $f(i, y) = +\infty$ for $i = n$ and all $y > a_i$.

## 代码实现
``` cpp 
void solve(){
	ll n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	ll l = 0, r = *max_element(all(a)) + k;
	while(l <= r){
		ll mid = (l + r) >> 1;
		bool ok = false;
        // 枚举a[i]成为mid的操作次数，当前操作次数 <= k，表示当前能够实现
		for(int i = 0; i < n; ++i){
			vector<ll> mn(n);
			mn[i] = mid;
			ll c = 0;
			for(int j = i; j < n; ++j){
				if(mn[j] <= a[j]) break;
				if(j + 1 >= n){
					c = k + 1;
					break;
				}
				c += mn[j] - a[j];
				mn[j + 1] = max(0LL, mn[j] - 1);
			}
			if(c <= k) ok = true;
		}
		if(ok){
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	cout << r << '\n';
}
```
