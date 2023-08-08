#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int judge2(int num){
    if(num == 0) return 0;
    int cnt = 0;
    while((num % 2) == 0){
        num /= 2;
        ++cnt;
    }
    return cnt;
}

int judge5(int num){
    if(num == 0) return 0;
    int cnt = 0;
    while((num % 5) == 0){
        num /= 5;
        ++cnt;
    }
    return cnt;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n);
        int x;
        for(int i = 0; i < n; ++i){
            cin >> x;
            a[i] = {judge2(x), judge5(x)};
//             cout << a[i].first << ' ' << a[i].second << "\n";
        }
        int ans = 0;
        int cnt2 = 0, cnt5 = 0;
        int l = 0, r = 0;
        while(r < n && (cnt2 + a[r].second <= k || cnt5 + a[r].second <= k)){
            while(l <= r && cnt2 - a[l].first >= k && cnt5 - a[l].first >= k){
                ++ans;
                cnt2 -= a[l].first;
                cnt5 -= a[l].second;
                ++l;
            }   
            cnt2 += a[r].first;
            cnt5 += a[r].second;
            if((cnt2 == k || cnt5 == k) && (cnt2 >= k && cnt5 >= k)) ++ans;
            ++r;
        }    
//         for(int l = 0, r = 0; r < n; ++r){
//             if((cnt2 == k || cnt5 == k) && (cnt2 >= k && cnt5 >= k)) ++ans;
//             if(cnt2 + a[r].first() > k && cnt5 + a[r].second() > k){
//                 while(cnt2 - a[l].first() >= k && cnt5 - a[l].second >= k){
//                     ++ans;
//                 }
//             }
//             cnt2 += a[r].first();
//             cnt5 += a[r].second();
//         }
        cout << ans << "\n";
    }
    return 0;
}