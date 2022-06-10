class Solution {
public:
//         void find(int low,string &s,vector<string> &ans,int high)
// {
//     if(low==high)
//     {
           
//         ans.push_back(s);
//     }
//     else
//     {
//         for(int i=low;i<=high;i++)
//         {
//             swap(s[low],s[i])           ;
//             find(low+1,s,ans,high);
//             swap(s[low],s[i]);
//         }
//     }
// }
    string getPermutation(int n, int k) {
    
            vector<int> numbers;
            int fact=1;
            for(int i=1;i<n;i++)
            {
                    fact=fact*i;
                    numbers.push_back(i);
            }
            numbers.push_back(n);
            k=k-1;
            string  ans="";
            while(true)
            {
                    ans+=to_string(numbers[k/fact]);
                    numbers.erase(numbers.begin()+k/fact);
                    if(numbers.size()==0)
                    {
                            break;
                    }
                    k=k%fact;
                    fact=fact/numbers.size();
            }
            return ans; 
    }
};