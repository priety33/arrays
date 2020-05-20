#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int l, int mid, int h, long &c)
{
    int i=l, j=mid+1, k=0;
    vector<int> temp (h-l+1);
    while(i<=mid && j<=h)
    {
        if(v[i]>v[j])
        {
            c+=mid-i+1;
            temp[k]=v[j];
            k++; j++;
        }
        else
        {
            temp[k]=v[i];
            k++; i++;
        }
    }
    while(j<=h) temp[k++]=v[j++];
    while(i<=mid) temp[k++]=v[i++];
    for(int i=l,k=0; i<=h; i++,k++) v[i]=temp[k];
}

void mergesort( vector<int> &v, int l, int h, long &c)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        mergesort(v, l, mid, c);
        mergesort(v, mid+1, h, c);
        merge(v, l, mid, h, c);
    }
}

int main() {
	int t; cin>>t;
	while(t--)
	{
	    int n; cin>>n;
	    vector<int> a(n, 0);
	    for(int i=0; i<n; i++) cin>>a[i];
	    long ans=0;
	    mergesort(a, 0, n-1, ans);
	    cout<<ans<<endl;
	}
	return 0;
}
