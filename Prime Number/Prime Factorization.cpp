// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

const int mx=1e8+232;
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

int main() {
   
   int lim=1e8;
   Gen_prime(lim);
   
   int n;
   cin>>n;
   vector<int>d;
   int i=0;
   while(n>0){
       
       if(n<prime[i])break;
       
       if(n%prime[i]==0){
           n/=prime[i];
           d.push_back(prime[i]);
       }
       else{
           i++;
       }
       
   }
   
    for(auto i:d)cout<<i<<" ";
   
}
