 // Hackerearth Link : https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/hacker-with-prime-bebe28ac/

#include <bits/stdc++.h>
using namespace std;

#define fastIO                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    cout.precision(numeric_limits<double>::max_digits10);

#define int long long

const int N=2e6+10;
int a[N];
int hp[N];
int canRemove[N];
int hsh[N];

vector<int> distinctPF(int x){

     vector<int>ans;
     while(x>1){
       
          int pf=hp[x];
          while(x%pf==0)x/=pf;
          ans.push_back(pf);
     }
     return ans;
}

void solve() {
  
  
      for(int i=2;i<N;i++){
        
          if(hp[i]==0){
             
              for(int j=i;j<N;j+=i){
                
                  hp[j]=i;
              }
          }
      }
      
 
         int n,q; cin>>n>>q;
         
         for(int i=0;i<n;i++){
           
             int x; cin>>x; 
             hsh[x]=1;
         }
         
         
         for(int i=2;i<N;i++){
           
             if(hsh[i]){
               
                 for(int j=i;j<N;j*=i)canRemove[j]=1;
             }
         }
        
          
         
       
         
         while(q--){
           
           int x; cin>>x;
           
           vector<int>pf=distinctPF(x);
           
           
           bool isPossible=false;
           
           for(int i=0;i<pf.size();i++){
             
               for(int j=i;j<pf.size();j++){
                 
                 int product=pf[i]*pf[j];
                 
                 if(i==j && x%product!=0 )continue;
                 
                 int toRemove=x/product;
                 
                 if(canRemove[toRemove] || toRemove==1){
                   isPossible=true;
                   break;
                 }
                   
               }
               
               if(isPossible)break;
           }
           
           cout<<(isPossible?"YES\n":"NO\n");
           
             
         }
   
     
}

// tc : 
// sc : 

int32_t main() {
    fastIO;

        solve();
    
    return 0;
}
