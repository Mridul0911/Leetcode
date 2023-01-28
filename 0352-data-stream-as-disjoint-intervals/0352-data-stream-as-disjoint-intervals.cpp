class SummaryRanges {
public:
        set<int> st;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
      int start=-1;
      int end=-1;
      for(auto  &item:st) {
          if(start == -1) 
          {
              start=item;
              end=item;
          } 
          else if(item==end + 1) 
          {
              end=item;
          } 
          else 
          {
              res.push_back({start, end});
              start=end=item;
          }
      }
      if(start!=-1) res.push_back({start, end});
      return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */