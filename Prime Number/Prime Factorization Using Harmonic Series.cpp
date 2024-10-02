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

const int maxi=1e7+322;
vector<int> factors[maxi];

int main() {
   
   int lim=1e6;
   Gen_prime(lim);
  
 
   for(auto p:prime){
       
       for(int i=p;i<lim;i+=p){
           int n=i;
           
           while(n%p==0){
               factors[i].push_back(p);
               n/=p;
           }
           
       }
   }
   
   for(int i=1;i<=20;i++){
       cout<<i<<" :";
       for(auto j:factors[i])cout<<j<<" ";
       cout<<endl;
   }
   
   
}
