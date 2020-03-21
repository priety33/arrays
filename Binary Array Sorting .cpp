#include <iostream>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--)
	{
	    int n; cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    int start=0, end=0;
	    while(a[start]==0) start++;
	    end=start;
	    while(a[end]==1) end++;
	    while(start<end && end<n)
	    {
	        if(a[end]==0)
	        {
	            swap(a[start],a[end]);
	            start++;
	            end++;
	        }
	        else end++;
	    }
	    for(int i=0;i<n;i++) cout<<a[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
