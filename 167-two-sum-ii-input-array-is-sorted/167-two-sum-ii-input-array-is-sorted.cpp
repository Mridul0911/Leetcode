class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    int i=0;
        int j=numbers.size()-1;
        while(i<j)
        {
            int x=numbers[i]+numbers[j];
            if(x>target)
            {
                j--;
            }
            else if(x<target)
            {
                i++;
            }
            else
            {
                vector<int> u;
                u.push_back(i+1);
                u.push_back(j+1);
                return u;
            }
        }
    return vector<int>();
    
    
    }
};