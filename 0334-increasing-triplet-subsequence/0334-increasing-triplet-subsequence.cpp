class Solution {
public:
//         void findPrevGreater(vector<int> &arr,int n,vector<int> &prev)
//         {
//                stack<int> s;
//             for (int i = 0; i < n; i++)
//             {
//                 while (!s.empty())
//                 {
//                     if (s.top() < arr[i])
//                     {
//                         prev.push_back(s.top());
//                         break;
//                     }
//                     else {
//                         s.pop();
//                     }
//                 }
//                 if (s.empty()) 
//                 {
//                      prev.push_back(-1);
//                 }
//                 s.push(arr[i]);
//             }
//         }
//         void findNextGreater(vector<int> &input,int n,vector<int> &next)
//         {
//             stack<int> s;
 
//     for (int i = n - 1; i >= 0; i--)
//     {
//         while (!s.empty())
//         {
//             if (s.top() <= input[i]) 
//             {
//                 s.pop();
//             }
//             else 
//             {
//                 next.push_back(s.top());
//                 break;
//             }
//         }
//         s.push(input[i]);
//     }
//      }
    bool increasingTriplet(vector<int>& nums) {
        // vector<int> next;
        // vector<int> prev;
        //    findNextGreater(nums,nums.size(),next);
        //    findPrevGreater(nums,nums.size(),prev); 
        //     for(int i=1;i<nums.size()-1;i++)
        //     {
        //             if(next[i]!= -1  && prev[i]!=-1)
        //             {
        //                     return true;
        //             }
        //     }
        //     return false;
            int len = nums.size();
        if(len<3)
        {
            return false;
        }
       int i=INT_MAX;
            int j=INT_MAX;
            for(auto it:nums)
            {
                    if(i>it)
                    {
                            i=it;
                    }
                    else if(it>i && it<j)
                    {
                            j=it;
                    }
                    else if(it>j)
                    {
                            return true;
                    }
            }
            return false;
    }
};