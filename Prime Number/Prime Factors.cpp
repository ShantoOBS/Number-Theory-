// Code -Link : https://vjudge.net/problem/UVA-583

// Online C++ compiler to run C++ program online
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

vector<int> primeFactors ( int n ){
    
      vector<int>factors;
      
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

int main() {
   
   int lim=1e7;
   Gen_prime(lim);
   
   int n;
   while(cin>>n){
       
         if ( n == 0 ) break;

        bool isNeg = false;
        if ( n < 0 ) {
            isNeg = true;
            n *= -1;
        }

        vector<int> factors = primeFactors(n);
        if ( isNeg ) {
            n *= -1;
            factors.insert(factors.begin(), -1);
        }

        cout << n << " = " << factors[0];
        for ( int i = 1; i < factors.size(); i++ ) cout << " x " << factors[i];
        cout << endl;
    }
       

}
