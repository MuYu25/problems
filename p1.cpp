#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int T;
    cin >> T;
    while(T--){
        ll n;
        cin >> n;
        int matrix[2][n];
        ll mx = 2 * n;
        matrix[0][0] = mx ;
        matrix[1][n-1] = mx - 1;
        int l = 1, r = mx - 2;
        bool ok = 0;
        for(int i = 0; i < n - 1; ++i){
            if(ok){
                matrix[0][i+1] = r--;
                matrix[1][i] = r--;
            }else{
                matrix[1][i] = l++;
                matrix[0][i+1] = l++;
            }
            ok = !ok;
        }
        for(int i = 0; i < 2; ++i){
            for(int j = 0; j < n; ++j){
                printf("%2d ", matrix[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
