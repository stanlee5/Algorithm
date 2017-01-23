class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort (nums.begin(), nums.end());
        int i,j,k,n=nums.size(),s;
        int ans=nums[0]+nums[1]+nums[2];
        
        for (i=0;i<n-2;i++)
        {
            j=i+1,k=n-1;
            while (j<k)
            {
                s = nums[i]+nums[j]+nums[k];
                if (s < target) j++;
                else if (s > target) k--;
                else if (s==target)
                    return target;
                
                if (abs(target-ans)>abs(target-s))
                    ans=s;
            }
        }
        return ans;
    }
};
