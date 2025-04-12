#include<bits/stdc++.h>
using namespace std;

const int M=1e9+7;

int binaryExponenItera(int a,int b){
  
    long long ans=1;
    
    while(b){
        if(b&1){
            ans= ( ans *1LL* a ) % M;
        }
        a= (a *1LL* a) % M;
        b>>=1;
        
    }
    return ans;
    
    
}

int main()
{
   int a; cin>> a; 
   
   cout<<binaryExponenItera(a,M-2)<<endl;
  
}
