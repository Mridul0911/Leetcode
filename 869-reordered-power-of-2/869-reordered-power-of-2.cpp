class Solution {
public:
        bool check(string str)
        {
                int num = 0;
	        for(int i=0;i<str.size();i++)
	        {
        		num=num*10+(str[i]-'0');
        	}
                int gg=(num&(num-1));
                if(gg==0)
                {
                        return true;
                }
                return false;
        }
        void find(string &str,int index,bool &ans)
        {
	        if(index==str.size())
	        {
        		if(str[0]!='0' && check(str))ans = true;
        		return;
        	}
        	for(int i=index;i<str.size();i++)
	        {
        		swap(str[i],str[index]);
        		find(str,index+1,ans);
        		swap(str[i],str[index]);
        	}
        }
    bool reorderedPowerOf2(int n) {
            bool ans=false;
        string s=to_string(n);
            find(s,0,ans);
            return ans;
    }
};