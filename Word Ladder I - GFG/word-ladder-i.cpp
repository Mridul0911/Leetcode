// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        int flag=0;
        for(auto it:wordList)
        {
            if(it==targetWord)
            {
                flag=1;
            }
        }
        if(!flag)
        {
            return 0;
        }
        set<string> st;
        for(auto it:wordList)
        {
            st.insert(it);
        }
        
        int ans=0;
        queue<string> q;
        q.push(startWord);
        while(!q.empty())
        {
            int n=q.size();
            ans++;
            while(n--)
            {
                string s=q.front();
                q.pop();
                for(int i=0;i<s.size();i++)
                {
                    string temp=s;
                    for(char gg='a';gg<='z';gg++)
                    {
                        temp[i]=gg;
                        if(temp==s) continue;
                        if(temp==targetWord){
                            return ++ans;
                        }
                        if(st.find(temp)!=st.end())
                        {
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends