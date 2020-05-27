//taking every element to their correct position
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int i=0, n=nums.size();
        while(i<n) {
            if(nums[i]==i+1 || nums[nums[i]-1]==nums[i]) i++;
            else {
                while(nums[i]!=i+1 && nums[nums[i]-1]!=nums[i]) {
                    swap(nums[i], nums[nums[i]-1]);
                }
                if(nums[i]==i+1) i++;
                else {
                    int j=i+1;
                    while(j<n && nums[j]==j+1) j++;
                    if(j==n) i++;
                    else swap(nums[i],nums[j]);
                }
            }
        }
        for(int i=0; i<n; i++) if(nums[i]!=i+1) ans.push_back(i+1);
        return ans;
    }
};

//for every element, making the number at its position negative, if it was positive
//at end missing numbers will be at positions where nums[i] is positive
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            int pos= abs(nums[i])-1;
            if(nums[pos]>0) nums[pos]=-nums[pos];
        }
        for(int i=0; i<nums.size(); i++) if(nums[i]>0) ans.push_back(i+1);
        return ans;
    }
};
