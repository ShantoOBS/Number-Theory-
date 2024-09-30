//T.C: O(nln(n))
//S.C: O(1e8)

// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

const int mx = 1e8;
bool isPrime[mx];
vector<int> primes;

void primeGen ( int n )
{
    for ( int i = 2; i <= n; i++ ) isPrime[i] = 1;


    for ( int i = 2; i <= n; i++ ) {
            for ( int j = i+i; j <= n; j += i ) {
                isPrime[j] = 0;
            }
    }


    for ( int i = 2; i <= n; i ++ ) {
        if(isPrime[i] == 1) {
            primes.push_back(i);
        }
    }

}

int main() {


     int lim;
     cin>>lim;

       primeGen(lim);

       for(int i=0;i<primes.size();i++){
           cout<<primes[i]<<" ";
       }

}

