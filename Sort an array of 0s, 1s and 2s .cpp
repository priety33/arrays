#include <iostream>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--)
	{
	    int n; cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    int start=0,mid=0,end=n-1;
	    while(start<n && a[start]==0) start++;
	    mid=start;
	    while(mid<n && a[mid]==1) mid++;
	    while(a[end]==2) end--; //mid and end now point at unknowns
	    while(mid<=end) //always use <= for edge cases
	    {
	        if(a[mid]==1) mid++;
	        else if(a[mid]==2)
	        {
	            swap(a[mid],a[end]);
	            end--;
	        }
	        else if(a[mid]==0)
	        {
	            swap(a[mid],a[start]);
	            start++;
	            mid++;
	        }
	    }
	    for(int i=0;i<n;i++) cout<<a[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
