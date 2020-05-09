class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        if(arr.size()<=1) return;
        int n=arr.size();
        int i=0, size=0, count=0; //count gives total no of zeroes to put in new array
        while(i<n && size<n)
        {
            if(arr[i]==0)
            {
                size++, count++;
                if(size==n)
                {
                    i++;
                    break;
                }
                count++;
            }
            size++;
            i++;
        }
        if(i==n) return;
        i--;
        for(int j=n-1; j>=0; j--)
        {
            if(arr[i]==0)
            {
                if(count&1) //edge case when last zeroes only one cope is duplicated
                {
                    arr[j]=0;
                    count--;
                }
                else
                {
                    arr[j]=0;
                    j--;
                    if(j>=0) arr[j]=0;
                    count-=2;
                }
            }
            else arr[j]=arr[i];
            i--;
        }
        return ;
    }
};
