// https://www.spoj.com/problems/ETF/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

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

int PHI ( int n ){
    
    int phi=n;
    
    for(auto p:prime){
      
       if(1LL*p*p > n)break;
       
          if(n%p==0){
            
                while(n%p==0)n/=p;
            
                phi/=p;
                phi*=(p-1);
          }
    }
    
    if(n>1){
      
        phi/=n;
        phi*=(n-1);
    }
    
    return phi;
}

int main() {
   
   int lim=1e7;
   Gen_prime(lim);
   
   
   int t; cin>>t;
   
   while(t--){
     
   
   int n; cin>>n;
   
   
   cout<<PHI(n)<<endl;
   
   }

}
