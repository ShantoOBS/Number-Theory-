// LightOJ - Link : https://lightoj.com/problem/false-ordering

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int NOD[1004];

int main() {


     int lim=1000;
     
     for(int i=1;i<=lim;i++){
         
         for(int j=i;j<=lim;j+=i){
             
             NOD[j]++;
         }
     }
     
     vector<pair<int,int>>v;
     
     for(int i=1;i<=lim;i++){
         v.emplace_back(NOD[i],-i);
     }
     
     sort(v.begin(),v.end());
     
     
     
     int T; cin>> T;
     
     for(int i=1;i<=T;i++){
        
        long long n; cin>> n;
        
        cout<<"Case "<<i<<": "<<(v[n-1].second*-1)<<endl;
         
     }

}
