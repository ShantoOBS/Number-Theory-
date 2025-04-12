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

/* There are N children and K toffees, K< N
   Count the number of ways to distribute toffee 
   among N students such thata eacth students get 
   1 toffee only --> nCk % M , M=1e9+7
   N < 10 ^ 6, K < N < 10 ^ 6 
   n! / ( (n-r)! * r! ) 
   Q < 1e5
   */

int const N=1e6+10;
int fac[N];

int main()
{
   
  fac[0]=1;
  
   for(int i=1;i<N;i++){
      fac[i]=(fac[i-1]* 1LL * i ) % M;
   }
   
   int q; cin>>q;
   
   while(q--){
     
        int n, k; cin>>n>>k;
        
        int ans=fac[n];
        
        int den=(fac[n-k] * 1LL * fac[k] ) % M;
        
        ans = ans * binaryExponenItera(den,M-2);
        
        cout<<ans<<endl;
   }
   
   
   
   
   
}
