class Solution {
public:
    void bfs(vector<vector<char>> grid, vector<vector<int>> &vis, int& i, int& j)
    {
        vis[i][j]=1;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        vector<int> di = {-1,0,1,0};
        vector<int> dj = {0,-1,0,1};
        q.push({i,j});
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int d=0;d<4;d++)
            {
                int ri = row+di[d];
                int cj = col+dj[d];
                if(ri>=0 && ri<m && cj>=0 && cj<n && grid[ri][cj]=='1' && !vis[ri][cj])
                {
                    vis[ri][cj]=1;
                    q.push({ri,cj});
                }
            }
        }


    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(m, vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==0)
                {
                    ans++;
                    bfs(grid, vis, i, j);
                }
            }
        }
        return ans;
    }
};
