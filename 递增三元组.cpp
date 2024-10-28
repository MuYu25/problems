#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    int x, mx = 0;
    ll arr[100006];
    ll arr1[100006];
    ll arr2[100006];
    for(int i = 0; i < n; i++){
        cin >> x;
        arr[x]++;
        if(x > mx) mx = x;
    }
    for(int i = 1; i <= mx; i++) {
        arr[i] += arr[i-1]; 
        cout << "arr " << i << ":" << arr[i] << endl;
    }
       
    
    for(int i = 0; i < n; i++){
        cin >> x;
        arr1[x] += arr[x - 1];
        if(x > mx) mx = x;
    }
    cout << "arr1[19]" << arr1[19] << endl;
    for(int i = 1; i <= mx; i++) {
        arr1[i] += arr1[i-1];
        cout << "arr1 " << i << ":" << arr1[i] << endl;
    }
        
    
    for(int i = 0; i < n; i++){
        cin >> x;
        arr2[x] += arr1[x - 1];
        if(x > mx) mx = x;
    }
    for(int i = 1; i <= mx; i++){
        arr2[i] += arr2[i-1];
        cout << "arr2 " << i << ":" << arr2[i] << endl;
    }
        

    cout << arr2[mx] << endl;
    return 0;
}

/*

10 
36 32 31 87 6 14 86 47 12 60 
70 95 78 12 19 19 47 10 3 85 
90 22 13 37 57 5 39 20 99 68

*/