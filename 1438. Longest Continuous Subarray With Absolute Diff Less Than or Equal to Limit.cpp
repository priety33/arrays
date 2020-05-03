class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        int len=0;
        int s=0,e=0;
        pair<int,int> low={nums[0],0}, high={nums[0],0};
        while(s<n && e<n)
        {
            if(nums[e]>high.first) high={nums[e], e};
            if(nums[e]<low.first) low={nums[e], e};
            
            if(high.first-low.first>limit)
            {
                if(nums[e]==low.first)
                {
                    int temp=high.second+1;
                    s=temp;
                    high={nums[temp], temp};
                    while(temp<e)
                    {
                        if(nums[temp]>high.first) high={nums[temp], temp};
                        temp++;
                    }
                }
                else if(nums[e]==high.first)
                {
                    int temp=low.second+1;
                    s=temp;
                    low={nums[temp], temp};
                    while(temp<e)
                    {
                        if(nums[temp]<low.first) low={nums[temp], temp};
                        temp++;
                    }
                }
            }
            if(high.first-low.first<=limit)
            {
                len=max(len, e-s+1);
                e++;
            }
        }
        return len;
    }
};
