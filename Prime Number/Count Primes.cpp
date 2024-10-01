// Leet -Code Link :https://leetcode.com/problems/count-primes/description/

const int mx = 1e7+123;
class Solution {
public:
    
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
 
    isPrime[2] = 1;
    primes.push_back(2);
 
    for ( int i = 3; i <= n; i += 2 ) {
        if(isPrime[i] == 1) {
            primes.push_back(i);
        }
    }
} 

    int countPrimes(int n) {
        if(n<3)return 0;

        primeGen(n-1);

        return primes.size();
        
    }
};
