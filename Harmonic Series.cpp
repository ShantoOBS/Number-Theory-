// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int mx=1e6;

int arr[mx];

int main() {
    
    
    int n;
    cin>>n;
     
     for(int i=1;i<=1e6;i++){
         for(int j=i;j<1e6;j+=i){
             arr[j]++;
         }
     }  
     
     for(int i=1;i<=n;i++){
         cout<<arr[i]<<" ";
         
     }
}
