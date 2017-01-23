class Solution {
public:
    void search(vector<vector<int>> &res, vector<int>::reverse_iterator s, vector<int>::reverse_iterator e, vector<int> &add, int target, int sum)
    {
        if (target==sum)
            res.push_back(add);
        else if (target > sum)
        {
            for (auto p=s; p!=e;p++)
            {
                int cnt=1;
                while (p+1!=e && *p==*(p+1))
                    p++, cnt++;

                for (int i=1;i<=cnt;i++)
                {
                    add.push_back(*p);
                    search(res, p+1, e, add, target, sum+*p*i);
                }
                
                while (cnt--)
                    add.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort (candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> add(0);
        search (res, candidates.rbegin(), candidates.rend(), add, target, 0);
        return res;
    }
};
