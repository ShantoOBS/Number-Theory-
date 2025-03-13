//Toph Link : https://toph.co/p/life-of-phi
//T.C: O(n log n)
//S.C: O(n)

#include <bits/stdc++.h>
using namespace std;
const int X=1e6+14;
vector<bool>is_prime(X);
vector<int>prime;

void prime_gen(int limt){

       for(int i=3;i<=limt;i+=2)is_prime[i]=true;

       for(int i=3;i<=sqrt(limt);i+=2){

             if(is_prime[i]){

                   for(int j=i*i;j<=limt;j+=i) is_prime[j]=false;
             }
       }

    prime.push_back(2);

    for(int i=3;i<=limt;i+=2)if(is_prime[i])prime.push_back(i);

}

const int MX=1e6+123;
long long phi[MX];

int main() {

     int limt=1e6;

     prime_gen(limt);

     for(int i=1;i<=limt;i++)phi[i]=i;

     for(auto p:prime){

           for(int j=p;j<=limt;j+=p){
                phi[j]/=p;
                phi[j]*=(p-1);
           }
     }

     int t; cin>> t;

       while(t--){

           long long x; cin>>x;


             long long sum=( x* (x-1) ) / 2;
             long long p=( phi[x]*x )/2;

             cout<<sum-p<<endl;

       }
}
