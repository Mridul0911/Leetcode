class BrowserHistory {
public:
        list<string> st;
        list<string> :: iterator it;
    BrowserHistory(string homepage) {
        st.push_back(homepage);
            it=st.begin();
    }
    
    void visit(string url) {
        auto gg=it;
            gg++;
            st.erase(gg,st.end());
            st.push_back(url);
            it++;
    }
    
    string back(int steps) {
        while(it!=st.begin() && steps--)
        {
              it--;  
        }
            return *it;
    }
    
    string forward(int steps) {
            auto gg=st.end();
            gg--;
        while(it!=gg && steps--)
        {
                it++;
        }
            return *it;
    }
};