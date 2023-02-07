class RangeFreqQuery {
public:
        int size=0;
        unordered_map<int,vector<int>> mp;
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0;i<arr.size();i++)
        {
                mp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        int lower_value=lower_bound(mp[value].begin(),mp[value].end(),left)-mp[value].begin();
        int upper_value=upper_bound(mp[value].begin(),mp[value].end(),right)-mp[value].begin();
         //   cout<<upper_value<<" "<<lower_value<<endl;
            return upper_value-lower_value;
    }
};