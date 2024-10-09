// CodeFroces Link : https://codeforces.com/contest/776/problem/B

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

const int mx = 1e6+124;
bitset<mx> isPrime;
vector<int> primes;

void primeGen ( int n )
{
    for ( int i = 3; i <= n; i += 2 ) isPrime[i] = 1;

    int sq = sqrt(n);
    for ( int i = 3; i <= sq; i += 2 ) {
        if(isPrime[i]) {
            for ( int j = i*i; j <= n; j += i ) {
                isPrime[j] = 0;
            }
        }
    }

    primes.push_back(2);

    for ( int i = 3; i <= n; i += 2 ) {
        if(isPrime[i] == 1) {
            primes.push_back(i);
        }
    }
}

int NOD(int n){
    
    int result=1;
    
    for(auto p:primes){
        
        if( 1LL* p*p > n)break;
        
        if(n%p==0){
            
            int cnt=0;
            while(n%p==0){
                cnt++;
                n/=p;
            }
            cnt++;
            result*=cnt;
        }
        
    }
    
    if(n>1){
        result*=2;
    }
    
    return result;
}

int main() {


     int lim=1e5;
     primeGen(lim);
    
     int n; cin>> n;
     
     cout<<NOD( n )<<endl;

}
