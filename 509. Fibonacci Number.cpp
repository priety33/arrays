/*
Nth Fibonacci number: 
matrix({1,1},{1,0})^n = {fib n+1, fib n}, {fib n, fib n-1}
*/
class Solution {
public:
    
    void multiply(int a[2][2], int b[2][2])
    {
        int x= (a[0][0]*b[0][0])+(a[0][1]*b[1][0]); //matrix multiplication?
        int y= (a[0][0]*b[0][1])+(a[0][1]*b[1][1]);
        int z= (a[1][0]*b[0][0])+(a[1][1]*b[1][0]);
        int w= (a[1][0]*b[0][1])+(a[1][1]*b[1][1]);
        
        a[0][0]=x, a[0][1]=y, a[1][0]=z, a[1][1]=w;
    }
    
    void matrixpower(int a[2][2], int n)
    {
        if(n<=1) return;
        matrixpower(a, n/2);
        multiply(a,a);
        int b[2][2]={{1,1},{1,0}};
        if(n%2!=0) multiply(a,b);
    }
    
    int fib(int N) {
        if(N<=1) return N;
        int a[2][2]={{1,1},{1,0}};
        matrixpower(a,N-1);
        return a[0][0];
    }
};
