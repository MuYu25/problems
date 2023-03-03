#include<bits/stdc++.h>

using namespace std;

const int maxn = 100010, INF = 0X7f7f7f7f, MOD = 100003;

int arr[maxn];

int query(int x, int len){
    for(int i = 1; i <= len; i++){
        if(arr[i] == x) return i;
    }   
    return -1;
}

int main(){
    int n, b;
    cin >> n >> b;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    int index = query(b, n);
    map<int, int> one;
    map<int, int> two;
    two[0] = 1;
    int val = 0;
    for(int i = index - 1; i > 0; i--){
        val += (arr[i] > b ? 1 : -1);
        if((index - i) % 2) one[val] += 1; 
        else two[val] += 1;
    }
    long long ans = 0;
    val = 0;
    for(int i = index; i <= n; i++){
        val += (arr[i] == b ? 0 : (arr[i] > b ? 1 : -1));
        if((i - index) % 2) ans += one[-val];
        else ans+= two[-val];
    }
    cout << ans << endl;
    return 0;
}