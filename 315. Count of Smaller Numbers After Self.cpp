/*
Complexities:
Time: O(n log n)
Space: O(n)
/*
// counting inversions fro each element and storing it

class Solution {
public:
    
    void mergesort( vector<pair<int,int>> &v, vector<int> &ans, int s, int e)
    {
        int mid=(s+e)/2;
        
        if(s<e)
        {
            mergesort(v, ans, s, mid);
            mergesort(v, ans, mid+1, e);
            merge(v, ans, s, mid, e);
        }
        return;
    }
    
    void merge(vector<pair<int,int>> &v, vector<int> &ans, int s, int mid, int e)
    {
        int i=s, j=mid+1;
        int c=0, k=0;
        vector<pair<int,int>> temp(e-s+1);
        
        while(i<=mid && j<=e)
        {
            if(v[i].first>v[j].first)
            {
                //inversion
                temp[k++]=v[j++];
                c++;
            }
            else
            {
                ans[v[i].second]+= c;
                temp[k++]=v[i++];
            }
        }
        
        while(i<=mid)
        {
            ans[v[i].second]+= c;
            temp[k++]=v[i++];
        }
        
        while(j<=e) 
        {
            temp[k++]=v[j++];
        }
        
        for(int i=s,j=0;j<k;j++,i++)
        {
            v[i]=temp[j];
        }
        
        return;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n, 0);
        if(n==0) return ans;
        
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++) v.push_back({nums[i], i});
        
        mergesort(v, ans, 0, n-1);
        return ans;
    }
};
