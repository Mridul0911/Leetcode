class Solution {
public:
    int minMovesToMakePalindrome(string input) {
       vector<int> freq(26,0);
    int odd=0; 
    int left=0;
    int len=0;
    for(int i=0;i<input.length();i++)
    {
        freq[input[i]-'a']++;
        len++;
    }
    int right=len-1;
    int result = 0;
    for(int i=0;i<26;i++)
    {
        if(freq[i]%2==1)
        {
            odd++;
        }
    }
    if(odd>1){
       return -1;
    }
    while(left<right) 
    {
        int l=left; 
        int r=right;
        while(input[l]!=input[r])
            r--;
        if(l==r) 
        {
            swap(input[r],input[r + 1]);
            result++;
            continue;
        }
        else 
        {
            while(r<right) 
            {
                swap(input[r],input[r + 1]);
                result++;
                r++;
            }
        }
        left++;
        right--;
    }
    return result; 
    }
};