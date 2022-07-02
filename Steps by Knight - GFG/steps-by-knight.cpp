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
	    queue<pair<int,pair<int,int>>> q;
	    q.push({0,{KnightPos[0],KnightPos[1]}});
	    int steps=0;
	    
	    vis[KnightPos[0]][KnightPos[1]]=true;
	    while(!q.empty())
	    {
	        int x=q.front().second.first;
	        int y=q.front().second.second;
	        int steps=q.front().first;
	        q.pop();
			if(x == TargetPos[0] and y == TargetPos[1])
				return steps;
	        
	        for(int i=0;i<8;i++)
	        {
	            int nx=x+dx[i];
	            int ny=y+dy[i];
	            if(isValid(nx, ny, N) and !vis[nx][ny])
	            {
					q.push({steps+1,{nx, ny}});
					vis[nx][ny] = true;
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