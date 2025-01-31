#include<bits/stdc++.h>
using namespace std;

vector<bool>isprime(1e6+123,false);
vector<int>prime;
vector<pair<int,int>>v1,v2;

bool flag=true;

void prime_gen(int lim){
  
    for(int i=3;i<=lim;i+=2){
        
        isprime[i]=true;
        
    }
    
    int sq=sqrt(lim);
    
    for(int i=3;i<=sq;i+=2){
        
          if(isprime[i]){
              
               for(int j=i*i;j<=lim;j+=i)isprime[j]=false;
          }
    }
    
    prime.push_back(2);
    
    for(int i=3;i<=lim;i+=2){
        if(isprime[i])prime.push_back(i);
    }
     
}

void NOD(int num1,int num2){
      
      if(flag==false)return;
      
      flag=false;
     
      for(auto p:prime){
            
            if(p*p>num1)break;
            
            if(num1%p==0){
                
                 int cnt=0;
                 
                 while(num1%p==0){
                     cnt++;
                     num1/=p;
                 }
                 
                 v1.emplace_back(p,cnt);
            }
      }
      
      if(num1>1){
          v1.emplace_back(num1,1);
      }
      
      
       for(auto p:prime){
                   if(p*p>num2)break;
            if(num2%p==0){
                
                 int cnt=0;
                 
                 while(num2%p==0){
                     cnt++;
                     num2/=p;
                 }
                 
                 v2.emplace_back(p,cnt);
            }
      }
      
      
      if(num2>1){
          v2.emplace_back(num2,1);
      }
    
}

int cal_gcd(int num1,int num2){
    
    NOD(num1,num2);
    
    vector<pair<int,int>>temp;
    
    for(int i=0;i<v1.size();i++){
        
        int p=v1[i].first;
        int n=v1[i].second;
        int m=v2[i].second;
        
        temp.emplace_back(p,min(n,m));
    }
    
    int ans=1;
    
    for(auto u:temp){
        
        ans*=pow(u.first,u.second);
    }
    
    return ans;
    
    
    
}


int cal_lcm(int num1,int num2){
    
    NOD(num1,num2);
    
    vector<pair<int,int>>temp;
    
    for(int i=0;i<v1.size();i++){
        
        int p=v1[i].first;
        int n=v1[i].second;
        int m=v2[i].second;
        
        temp.emplace_back(p,max(n,m));
    }
    
    int ans=1;
    
    for(auto u:temp){
        
        ans*=pow(u.first,u.second);
    }
    
    return ans;
    
    
    
}


int main(){
    
     int lim=1e6;
     
     prime_gen(lim);
     
     int num1,num2; cin>> num1 >> num2;
     
     cout<<cal_gcd(num1,num2)<<endl;
     cout<<cal_lcm(num1,num2)<<endl;

    
}
