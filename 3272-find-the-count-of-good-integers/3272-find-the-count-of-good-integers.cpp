class Solution {
public:
    long long count;
    unordered_map<int, long long> factCache;
    unordered_set<string> visited;
    long long factorial(int n) {
        if(factCache.find(n) != factCache.end())return factCache[n];
        long long result = 1;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return factCache[n] = result;
    }
    long long compute(vector<int>& digitCount){
        int n=0;
        for(int x: digitCount)n+=x;
        long long tot = factorial(n);
        for(int d=0;d<10;d++)tot/= factorial(digitCount[d]);
        return tot;
    }
    int findPermutation(string palindrome)
    {
        vector<int> digitCount(10, 0);
        int n = palindrome.size();
        for (char digit : palindrome) {
            digitCount[digit - '0']++;
        }
        long long tot = 0;        
        for(int d=0;d<10;d++){
            if(d and digitCount[d]){
                digitCount[d]--;
                tot += compute(digitCount);
                digitCount[d]++;
            }
        }
        return tot;
    }
    int isGoodPalindrome(string firstHalf, int n, int k) {
        string palindrome = firstHalf;
        if (n % 2 != 0) {
            palindrome += string(firstHalf.rbegin() + 1, firstHalf.rend());
        } else {
            palindrome += string(firstHalf.rbegin(), firstHalf.rend());
        }
        long long num = stoll(palindrome);
        
        if(num%k==0)
        {
            string pal2 = palindrome;
            sort(pal2.rbegin(), pal2.rend());
            if(visited.find(pal2) != visited.end())return 0;
            visited.insert(pal2);
            return findPermutation(palindrome);
        }
        else
        {
            return 0;
        }
    }
    long long countGoodIntegers(int n, int k) {
        unordered_map<string,int> mp;
        int halfLength = (n + 1) / 2;
        int start = pow(10, halfLength - 1);
        int end = pow(10, halfLength); 
        
        for (int i = start; i < end; ++i) {
            string firstHalf = to_string(i);
            count+=isGoodPalindrome(firstHalf,n,k);
        }
        return count;
    }
};