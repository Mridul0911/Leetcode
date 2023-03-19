class Solution {
public:
    bool isValid(int i,int j,int n,int m) {
        return i>=0&&j>=0&&i<n&&j<m;
    }
    void spread(queue<pair<int,int> > &q,vector<vector<int> > &a,vector<vector<int> > &visited,int time,int l,int ll,int mark) {
        int cnt=q.size(),nextCnt=0;;
        int n=a.size(),m=a[0].size();
        while(!q.empty()&&time) {
            auto p=q.front();
            int i=p.first, j=p.second;
            cnt--;
            q.pop();
            int x[]={0,0,-1,1};
            int y[]={-1,1,0,0};
            for(int k=0;k<4;k++) {
                int idx=i+x[k],idy=j+y[k];
                if(isValid(idx,idy,n,m)&&a[idx][idy]==0&&(visited[idx][idy]==l||visited[idx][idy]==ll)) {
                    visited[idx][idy]=mark;
                    nextCnt++;
                    q.push({idx,idy});
                }
            }
            if(cnt==0) {
                time--;
                cnt=nextCnt;
                nextCnt=0;
            }
        }
    }
    bool isPossible(int time,vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<vector<int> > visited(n,vector<int>(m,false));
        // 0 -> unvisited, 1-> fire visited, 2-> man visited
        queue<pair<int,int> > q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(a[i][j]==1) {
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        spread(q,a,visited,time,0,2,1);
        if(visited[0][0]==1) return false;
        queue<pair<int,int>> q2;
        q2.push({0,0});
        visited[0][0]=2;
        while(visited[n-1][m-1]==0&&time<=(2*n*m)) {
            time++;
            if(visited[n-2][m-1]==2||visited[n-1][m-2]==2) return true;
            spread(q,a,visited,1,0,2,1);
            spread(q2,a,visited,1,0,0,2);
        } 
        cout<<time<<" "<<visited[n-1][m-1]<<endl;
        if(visited[n-1][m-1]==2) return true;
        return false; 
    }
    
    int maximumMinutes(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        int low=0,high=(n*m)+1;
        int ans=n*m+1;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(isPossible(mid,a)) {
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        if(high==-1) return -1;
        if(ans==n*m+1) return (int)1e9;
        return ans;
    }
};