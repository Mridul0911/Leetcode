// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	bool isValid(int x, int y, int N){
		return (x >=0 and x < N and y >=0 and y < N);
 }
		
		
    vector<int> dx={2,2,1,-1,-2,-2,-1,1};
    vector<int> dy={1,-1,-2,-2,-1,1,2,2};
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    KnightPos[0]--;
	    KnightPos[1]--;
	    TargetPos[0]--;
	    TargetPos[1]--;
	    vector<vector<bool>> vis(N,vector<bool>(N,false));
	    queue<pair<int,pair<int,int>>> pq;
	    pq.push({0,{KnightPos[0],KnightPos[1]}});
	    while(!pq.empty())
	    {
	        int x=pq.front().second.first;
	        int y=pq.front().second.second;
	        int steps=pq.front().first;
	        pq.pop();
	        if(x==TargetPos[0] && y==TargetPos[1])
	        {
	            return steps;
	        }
	        for(int i=0;i<8;i++)
	        {
	            int xx=dx[i]+x;
	            int yy=dy[i]+y;
	            if(isValid(xx,yy,N) && !vis[xx][yy])
	            {
	                vis[xx][yy]=true;
	                pq.push({steps+1,{xx,yy}});
	            }
	        }
	    }
	    return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends