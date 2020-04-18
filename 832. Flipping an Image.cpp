class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m=A.size();
        int n=A[0].size();
        for(int i=0;i<m;i++)
        {
            int k=0,j=n-1;
            while(k<=j)
            {
                if(k!=j && A[i][k]^A[i][j]==0)
                {
                    A[i][k]=!A[i][k];
                    A[i][j]=!A[i][j];
                }
                else if(k==j) A[i][k]=!A[i][k];
                k++, j--;
            }
        }
        return A;
    }
};
