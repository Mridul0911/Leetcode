class Solution {
    public String longestPalindrome(String s) {
        if(s.equals("")|| s == null) return "";
        int windowsize = s.length();
        int left = 0, right = left + windowsize -1;
        while(windowsize>0)
        {
            int lp = 0, rp = lp + windowsize -1;
            while(rp<s.length())
            {
                if(isPal(s.substring(lp,rp+1)))
                return s.substring(lp,rp+1);
                else{
                    lp++;rp++;
                }
            }
            windowsize--;
            left = 0; right = left + windowsize -1;
        }
        return "";
    }
    public boolean isPal(String str)
    {
        int len = str.length();
        int l = 0, r= len-1;
        while(l<=r)
        {
            if(str.charAt(l)!=str.charAt(r)) return false;
            l++;r--;
        }
        return true;
    }
}