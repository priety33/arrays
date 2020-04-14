//gives tle in 10^9 cases
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        if(n==1) return 1;
        vector<long long> ans;
        int ai=1, bi=1, ci=1;
        for(int i=0;i<n;i++)
        {
            int x=min(a*ai, min(b*bi, c*ci));
            ans.push_back(x);
            if(x==a*ai) ai++;
            if(x==b*bi) bi++;
            if(x==c*ci) ci++;
        }
        return ans[n-1];
    }
};

//BINARY SEARCH

Formula
Calculate how many numbers from 1 to num are divisible by either a, b or c by using below formula:
num/a + num/b + num/c – num/lcm(a, b) – num/lcm(b, c) – num/lcm(a, c) + num/lcm(a, b, c)

https://leetcode.com/problems/ugly-number-iii/discuss/387780/C%2B%2B-Java-Binary-Search-with-Venn-Diagram-Explain-Math-Formula

typedef long long ll;
#define MAX_ANS 2e9 // 2 * 10^9

class Solution {
public:
    
    ll gcd(ll a, ll b)
    {
        if(a==0) return b;
        return gcd(b%a, a);
    }
    
    ll lcm(ll a, ll b)
    {
        return a*b/(gcd(a,b));
    }
    
    ll count( int n, int a, int b, int c)
    {
        return n/a + n/b + n/c - n/lcm(a,b) - n/lcm(b,c) -n/lcm(a,c) + n/lcm(a, lcm(b,c));
    }
    
    int nthUglyNumber(int n, int a, int b, int c) {
         int left = 0, right = MAX_ANS, result = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (count(mid, a, b, c) >= n) { // find mid as small as possible that count == n => we found till this numbers we have n such numbers =>                                                 //current number is the nth nymber
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};
