class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        int a[n];
        
        //finding minimum of every arr[i], on its rhs
        //chunk++ when max till i< min on its rhs
        a[n-1]=arr[n-1];
        int min_element=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            a[i]=min_element;
            min_element=min(min_element,arr[i]);
        }
        
        int max_element=INT_MIN;
        for(int i=0;i<n;i++)
        {
            max_element=max(max_element,arr[i]);
            if(i!=n-1 && max_element<=a[i]) //i!=n-1, checking because +1 is added for the last chunk before returning.
            {
                ans++;
                max_element=INT_MIN;
            }
        }
        
        return ans+1; //+1 for last chunk
    }
};
