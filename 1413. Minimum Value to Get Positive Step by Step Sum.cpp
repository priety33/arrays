class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int a=0, sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            a=min(a, sum);
        }
        if(a>=0) return 1;
        else return -a+1;
    }
};
