class Solution {
public:
    vector<int> getRow(int rowIndex) {
      vector<int> gg;
            long long int val=1;
            
            for(int i=0;i<=rowIndex;i++)
            {
                 gg.push_back(val);
                 val=(val*(rowIndex-i))/(i+1);
            }
            return gg;
        }
};