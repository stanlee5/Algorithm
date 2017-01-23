
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt[256]={0,},t=0,mx=0;
        auto p=s.begin();
        for (auto c=s.begin();c!=s.end();c++)
        {
            while (cnt[*c])
                cnt[*p]--, p++, t--;
            cnt[*c]=1, t++;
            mx = mx<t?t:mx;
        }
        return mx;
    }
};
