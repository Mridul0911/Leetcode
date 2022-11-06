class Solution {
public:
    string orderlyQueue(string s, int k) 
    {
        if(k == 1) 
        {                            
	        string str = s;
                for(int i = 0 ; i  <s.size() ;++i)
                {
                        char t = s[0];
                        for(int j = 0  ; j <s.size()-1 ;++j)
                        {
                                s[j] = s[j+1];
                        }
                        s[s.size()-1] = t;
                        str = min(str,s);
                }
                return str;
        } 
        sort(s.begin(),s.end());            
        return s;
}
}; 