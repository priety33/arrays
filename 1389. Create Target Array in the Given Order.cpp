class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            v.insert(v.begin()+index[i], nums[i]); //inserts an element after shifting subsequent elements forward.
        }
        return v;
    }
};
