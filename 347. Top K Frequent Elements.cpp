class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int  num : nums)
            ++m[num];
        /** as the word frequencies is at most nums.size() **/
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto p : m) 
            buckets[p.second].push_back(p.first);
        /** we can fetch the top k largest element value from the array **/    
        vector<int> ans;
        for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; --i)
        {
            for (int num : buckets[i])
            {
                ans.push_back(num);
                if (ans.size() == k)
                    break;
            }
        }
        return ans;
    }
};
