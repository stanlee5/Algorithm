class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        
        vector<vector<int>> d(n+1, vector<int>(m+1,0));
        d[1][0]=1;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (!obstacleGrid[i-1][j-1])
                    d[i][j] = d[i-1][j] + d[i][j-1];
        return d[n][m];
    }
};
