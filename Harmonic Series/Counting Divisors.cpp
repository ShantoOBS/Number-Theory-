// CSES-Link : https://cses.fi/problemset/task/1713/

// T.C : O(n ln(n) )
// T.C : O(1e6+123)

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
const int x=1e6+123;
int arr[x];
 
int main() {
    
   
    
    for(int i=1;i<=x;i++){
        
        for(int j=i;j<=x;j+=i){
            arr[j]++;
        }
    }
    
    
    
     int n;
    cin>>n;
    
    while(n--){
        
        int x;
        cin>> x;
        
        cout<<arr[x]<<endl;
    }
    
    
}
