//Brute Force Solution – O(N2) Approach-1

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin>> n;
    
    int ans=0;

    for(int i=1;i<=n;i++) {
        
        int cnt=0;
        
         for(int j=1;j<=i;j++){
             
              if(i%j==0)cnt++;
         }
         
         ans+=cnt;
         
    }
    
    cout<<ans<<endl;

}


//Using NOD() - O(N×(√N/ln(√N)) Approach-2

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

long long NOD(long long n){
    
    long long result=1;
    
    for(auto p:primes){
        
        if( 1LL* p*p > n)break;
        
        if(n%p==0){
            
            long long cnt=0;
            while(n%p==0){
                cnt++;
                n/=p;
            }
            cnt++;
            result*=cnt;
        }
        
    }
    
    if(n>1){
        result*=2;
    }
    
    return result;
}

int main(){
    
    int n;
    cin>> n;
    
    int lim=1e4;
    
    primeGen(lim);
    
    int ans=0;
    
    for(int i=1;i<=n;i++){
        
          ans+=NOD(i);
    }
    
    cout<<ans<<endl;

}


//Using Divisor List - O(N) Approach-3

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin>> n;
    
    int lim=1e4;
    
    
    int ans=0;
    
    for(int i=1;i<=n;i++){
        
          ans+=(n/i);
    }
    
    cout<<ans<<endl;

}

//Using Divisor Pairs - O(√N) Approach-4

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin>> n;

    int ans=0;
    
    int sqr=sqrt(n);
    
    for(int i=1;i<=sqr;i++){
        
          ans+=((n/i)-i)*2;
    }
    
    ans+=sqr;
    
    cout<<ans<<endl;

}


