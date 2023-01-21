//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string decToBinary(int n)
    {
        string s="";
        for (int i = 31; i >= 0; i--) {
            int k = n >> i;
            if (k & 1)
                s+="1";
            else
                s+="0";
        }
        return s;
    }
    int minVal(int a, int b) {
            string aa=decToBinary(a);
            string bb=decToBinary(b);
            int count=0;
            for(int i=0;i<bb.size();i++)
            {
                if(bb[i]=='1')
                {
                    count++;
                }
            }
          //  cout<<aa<<endl;
        //    cout<<bb<<endl;
            string s="";
            s.resize(32);
            for(int i=0;i<32;i++)
            {
                s[i]='0';
            }
            
            for(int i=0;i<aa.size();i++)
            {
                if(count==0)
                {
                    break;
                }
                if(aa[i]=='1')
                {
                    s[i]='1';
                    count--;
                }
                else
                {
                    s[i]='0';
                }
            }
            if(count)
            {
                for(int i=aa.size()-1;i>=0;i--)
                {
                    if(count==0)
                    {
                        break;
                    }
                    if(s[i]=='0')        
                    {
                        s[i]='1';
                        count--;
                    }
                }
            }
           // cout<<s<<endl;
            int i,N,decimal_number=0,p=0;
    N=s.size(); 
    for(i=N-1;i>=0;i--)
    {
        if(s[i]=='1') 
        {
            decimal_number+=pow(2,p);
        }
        p++;
    }
    return decimal_number;
                
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends