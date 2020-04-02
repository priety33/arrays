/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by 
the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops
endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

*/
class Solution {
public:
    
    int sum(int n)
    {
        int ans=0;
        while(n)
        {
            ans+=(n%10)*(n%10);
            n=n/10;
        }
        return ans;
    }
    
    bool isHappy(int n) {
        map<int,bool> m;
        while(!m[sum(n)]) //when a number is not happy, it goes into endless loop => values start repeating
        {
            m[sum(n)]=true;
            n=sum(n);
            if(n==1) return true;
        }
        return false;
    }
};


//without extra space
//two pointers slow,fast- just like finding loop in linked list, here they should meet at 1 for number to be happy

// Utility method to return sum of square of 
// digit of n 
int numSquareSum(int n) 
{ 
    int squareSum = 0; 
    while (n) 
    { 
        squareSum += (n % 10) * (n % 10); 
        n /= 10; 
    } 
    return squareSum; 
} 
  
//    method return true if n is Happy number 
bool isHappynumber(int n) 
{ 
    int slow, fast; 
  
    //    initialize slow and fast by n 
    slow = fast = n; 
    do
    { 
        //    move slow number by one iteration 
        slow = numSquareSum(slow); 
  
        //    move fast number by two iteration 
        fast = numSquareSum(numSquareSum(fast)); 
  
    } 
    while (slow != fast); 
  
    //    if both number meet at 1, then return true 
    return (slow == 1); 
} 
