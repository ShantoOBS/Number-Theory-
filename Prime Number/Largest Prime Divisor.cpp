// vjudge-link : https://vjudge.net/problem/UVA-11466

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
              factors.push_back(i);
              while(n%i==0){
                  n/=i;
              }
          }
      }
      
      if(n>1)factors.push_back(n);
      
      return factors;
}


int main() {
   
   int lim=1e7;
   Gen_prime(lim);
  
 
   ll n;
   while(cin>>n){
       
       if(n==0)break;
       
       n=abs(n);
       
       vector<ll>factor=primeFactors(n);
       
       if(factor.size()<=1)cout<<-1<<endl;
       else cout<<factor.back()<<endl;
       
   }
   
       
  
    
   
}
