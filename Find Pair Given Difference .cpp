//with space- hashmap
//this is in O(1) space

#include<bits/stdc++.h>   
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,diff; cin>>n>>diff;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        
        sort(a,a+n);
        
        int i=0, j=1; //if i=0, j=n-1 is taken, inr both cases:
                      // i++ and j--, difference will only decrease.
        int print=-1;
        while(i<n && j<n) //i<j will not work for negative difference.
        {
            if(a[j]-a[i]==diff)
            {
                print=1;
                break;
            }
            else if(a[j]-a[i]>diff)
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        cout<<print<<endl;
    }
}
