class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> arr;
        vector<vector<string>> res;
        for (auto s:strs)
        {
            string t=s;
            sort(s.begin(),s.end());
            if (arr.find(s)==arr.end())
                arr[s] = vector<string>(0);
            arr[s].push_back(t);
        }
        for (auto p:arr)
            res.push_back(vector<string>(p.second.begin(), p.second.end()));
        return res;
    }
};
