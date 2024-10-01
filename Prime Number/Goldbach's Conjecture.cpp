
// vJ link : https://vjudge.net/problem/UVA-543

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

int main() {


     int lim=1e6;
     primeGen(lim);
     
     int n;
     
     while(cin>>n){
         
         if(n==0)break;
         
         if(n==1){
              cout<<"Goldbach's conjecture is wrong."<<endl;
              continue;
         }
          
         bool flag=false;
          
         for(auto i:primes){
             if(i>n)break;
             int a=i;
             int b=n-i;
             
             if(isPrime[b]){
                 cout<<n<<" = "<<a<<" + "<<b<<endl;
                 flag=true;
                 break;
             }
         }
         
         if(flag==false){
             cout<<"Goldbach's conjecture is wrong."<<endl;
         }
    }
    
  return 0;

      
}
