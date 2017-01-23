class Solution {
public:

    int n,m;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    
    void bfs (vector<vector<char>> &grid, int x, int y)
    {
        queue<pair<int,int>> q;
        q.emplace (x,y);
        
        do
        {
            auto t=q.front();
            q.pop();
            x = t.first;
            y = t.second;
            for (int i=0;i<4;i++)
            {
                int tx=x+dx[i];
                int ty=y+dy[i];
                if (tx<n && ty<m && tx>=0 && ty>=0 && grid[tx][ty]=='1')
                {
                    grid[tx][ty]='0';
                    q.emplace (tx,ty);
                }
            }
        }while (!q.empty());
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        if (n==0)
            return 0;
        m=grid[0].size();
        int cnt=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
            {
                if (grid[i][j]=='1')
                {
                    cnt++;
                    bfs (grid, i,j);
                }
            }
        printf ("%d\n",cnt);
        return cnt;
    }
};
