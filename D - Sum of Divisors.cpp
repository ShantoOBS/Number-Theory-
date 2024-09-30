// At-Code Link : https://atcoder.jp/contests/abc172/tasks/abc172_d

// T.C : O(n ln(n) )
// T.C : O(1e7+123)
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

const int x=1e7+123;
int cnt[x];

int main() {
    
   int lim = 1e7;

    for ( int i = 1; i <= lim; i++ ) {
        for ( int j = i; j <= lim; j += i ) {
            cnt[j]++;
        }
    }

    int n;
    cin >> n;

    long long ans = 0;
    for ( int i = 1; i <= n; i++ ) {
        ans += ( 1LL * i * cnt[i] );
    }

    cout << ans << endl;
    
    
}
