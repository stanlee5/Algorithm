class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (!n) return 0;
        vector<vector<int>> d;
        d.push_back(vector<int>(n));
        d.push_back(vector<int>(n));
        
        d[1][0]=nums[0];
        for (int i=1;i<n;i++)
        {
            d[0][i]=max(d[0][i-1],d[1][i-1]);
            d[1][i]=d[0][i];
            if (i>1)
                d[1][i]=max(d[1][i],d[1][i-2]+nums[i]);
            else
                d[1][i]=max(d[1][i],nums[i]);
        }
        return max(d[0][n-1],d[1][n-1]);
    }
};
