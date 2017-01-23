class Solution {
public:
    int dis(pair<int,int> a, pair<int,int> b)
    {
        return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
    }
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n=points.size();
        int ans=0;
        for (int i=0;i<n;i++)
        {
            unordered_map<int,int> m;
            for (int j=0;j<n;j++)
                if (i!=j)
                    m[dis(points[i],points[j])]++;
            for (auto p:m)
                ans += p.second * (p.second-1);
        }
        return ans;
    }
};
