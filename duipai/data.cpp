#include<bits/stdc++.h>

using namespace std;

int MX = 1e5;

int main(){
    srand(time(0));
    int n = 10;
    cout << n;
    
    for(int i = 0; i < n; ++i){
        cout << rand() % MX << ' ';
    }
}

