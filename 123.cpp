#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int maxTotal(vevtor<vector<int>>& fruits, int startPos, int k){
        int left = lower_bound(fruits.begin(), fruits.end(), startPos - k, [](const auto &a, const int b){
            return a[0] < b;
        });
    }
}



int main(){
    int n;
    scanf("%d", &n);
    
}
