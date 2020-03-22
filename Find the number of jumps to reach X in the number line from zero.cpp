#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int n; cin>>n;
	int i=1;
    int jump=0;
    int pos;
    for(pos=0; pos<n; )
    {
        pos=pos+i;
        jump++;
        i++;
    }
    if((pos-n)%2==0) cout<<jump; //can reach required pos in even changes= 0,2,4 etc.
    else if((pos+i-n)%2==0) cout<<jump+1; //taking one more jump-> pos+i. Now can we reach required pos in even changes?
    else cout<<jump+2; //if previous jump was even and our difference (current pos- required pos) was still odd, this one
                         will be odd jump, and now the difference will be even.
	return 0;
}

/* 1+2+3...+x+..=y
   1+2+3...-x+..=y-2x =>making one negative jump, we make an even change-> 2x
                        therefore if we cant reach in all positive jumps, we have to make some negative jumps,
                        ie, when our difference becomes even this means we can make a negative jump
   */
