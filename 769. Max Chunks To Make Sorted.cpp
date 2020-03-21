class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0,large=0;
        for(int i=0;i<arr.size();i++)
        {
            large=max(large,arr[i]);
            if(large==i) ans++;
        }
        return ans;
    }
};
