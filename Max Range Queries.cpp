#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define cases lli testcases;cin>>testcases; while(testcases--)
#define trace(x) cerr << '>' << #x << ':' << x << endl;
 
lli l[100005],r[100005],A[100005];
lli prefixK[100005];//prefixK[i]= stores the cnt of K from 1 to i
lli postfixK[100005];//postfixK[i]= stores the cnt of K from i to M
lli cmkOne[100005];//cmkOne[i]= stores the cnt of (K+1) from 1 to i
lli n,k;
int32_t main()
{
    cases
    {
        lli i,j,AC=0;
        memset(A,0,sizeof(A));
        memset(prefixK,0,sizeof(prefixK));
        memset(postfixK,0,sizeof(postfixK));
        memset(cmkOne,0,sizeof(cmkOne));
        cin>>n>>k;
        for(i=0;i<n;i++)
        {
            cin>>l[i]>>r[i];// 1 based indexing
            A[l[i]]++;
            A[r[i]+1]--;
        }
        // Array A contains the array after performing all the N operations.
        for(i=1;i<=100001;++i)
        {
          A[i]=A[i]+A[i-1];
          cmkOne[i] = (A[i]==k+1) + cmkOne[i-1];
          prefixK[i]=(A[i]==k)+ prefixK[i-1];
        }
//      for(i=1;i<=11;i++)cout<<A[i]<<" ";cout<<endl;
        for(i=100000;i>=1;i--)
        {
            postfixK[i]=postfixK[i+1]+ (A[i]==k);
        }
        // Now checking by removing each range one by one.
        for(i=0;i<n;i++)
        {
          lli val=0,x=l[i],y=r[i];
          lli Kcnt=cmkOne[y]-cmkOne[x]+(A[x]==k+1);
          Kcnt+=prefixK[x-1]+postfixK[y+1];
          AC=max(AC,Kcnt);
          //trace(Kcnt);
        }
         cout<<AC<<endl;
    }
    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n\n";
    #endif
return 0;
}
