class Solution {
public:
    string removeKdigits(string nums, int k) 
    {
            if(k>=nums.length())
            {
                    return "0";
            }
            if(k==0)
           {
                    return nums;
            }
       stack<char> s;
            s.push(nums[0]);
            for(int i=1;i<nums.length();i++)
        {
            while(k && !s.empty() && nums[i]<s.top())
            {
                k--;
                s.pop();
            }
            s.push(nums[i]);
            if(s.size() == 1 && nums[i] == '0')
            {
                s.pop();
            }
        }
            while(k && !s.empty())
            {
                    k--;
                    s.pop();
            }
            string res="";
            while(!s.empty())
            {
                    res+=s.top();
                    s.pop();
            }
            
            reverse(res.begin(),res.end());
            if(res.size()==0)
            {
                    return "0";
            }
            return res;
    }
};