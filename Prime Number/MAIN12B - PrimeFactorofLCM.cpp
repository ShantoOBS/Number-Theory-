// SPOJ-Code Link : https://www.spoj.com/problems/MAIN12B/

// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using ll= long long;

const int mx=1e7+127;
bool is_prime[mx];
vector<int>prime;

void Gen_prime(int n){
    
    for(int i=3;i<=n;i+=2)is_prime[i]=1;
    
    prime.push_back(2);
    int lim=sqrt(n);
    for(int i=3;i<=lim;i+=2){
        
        if(is_prime[i]){
            
            for(int j=i*i;j<=n;j+=i){
                is_prime[j]=0;
            }
        }
    }
    
    for(int i=0;i<=n;i++){
        if(is_prime[i])
        prime.push_back(i);
    }
}



vector<ll> primeFactors ( ll n ){
    
      vector<ll>factors;
      
      for(auto i:prime){
          
          if( 1LL *i*i > n )break;
          
          if( n%i ==0 ){
              
              while(n%i==0){
                  factors.push_back(i);
                  n/=i;
              }
          }
      }
      
      if(n>1)factors.push_back(n);
      
      return factors;
}
ll a[200];

int main() {
   
   int lim=1e7;
   Gen_prime(lim);
   int T;
    cin >> T;
    for ( int tc = 1; tc <= T; tc++ ) {
        int n;
        cin >> n;
        for ( int i = 1; i <= n; i++ ) cin >> a[i];
 
        set<ll> ans;
        for ( int i = 1; i <= n; i++ ) {
            vector<ll> factors = primeFactors(a[i]);
            for ( auto p : factors ) {
                ans.insert(p);
            }
        }
 
        cout << "Case #" << tc << ": " << ans.size() << endl;
        for ( auto u : ans) {
            cout << u << endl;
        }
    }
  
   
}
