class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        
        //to ensure first matrix is always smaller one -> for faster binary search
        if(n>m){
            nums1.swap(nums2);
            int temp=n;
            n=m; m=temp;
        }
        
        int divide=(n+m+1)/2;
        int i=0, j=n;
        double ans=0;
        
        while(i<=j)
        {
            int mid1=(i+j)/2; 
            int mid2=divide-mid1;
            
            if(mid1>0 && mid2<m && nums1[mid1-1]>nums2[mid2])
            {
                j=mid1-1;
            }
            else if(mid1<n && mid2>0 && nums1[mid1]<nums2[mid2-1])
            {
                i=mid1+1;
            }
            else
            {
                int maxleft=0;
                if(mid1==0) maxleft=nums2[mid2-1];
                else if(mid2==0) maxleft=nums1[mid1-1];
                else maxleft= max(nums1[mid1-1], nums2[mid2-1]);
                
                if((m+n)&1) return maxleft;
                
                int minright=0;
                if(mid1==n) minright=nums2[mid2];
                else if(mid2==m) minright=nums1[mid1];
                else minright=min(nums1[mid1], nums2[mid2]);
                
                return (maxleft+minright)/2.0;
            }
        }
        
        return 0.0;
    }
};