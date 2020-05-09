class Solution {
public:
    
    static bool compare(vector<int> a, vector<int> b){
        return a[0]>b[0];
    }
    
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector<vector<int>> v;
        for(int i=0;i<values.size();i++) v.push_back({values[i],labels[i]});
        sort(v.begin(), v.end(), compare);
        int ans=0, i=0;
        unordered_map<int, int> m;
        while(i<values.size() && num_wanted)
        {
            if(m.find(v[i][1])==m.end() || m[v[i][1]]<use_limit){
                ans+=v[i][0];
                m[v[i][1]]++;
                num_wanted--;
            }
            i++;
        }
        return ans;
    }
};
