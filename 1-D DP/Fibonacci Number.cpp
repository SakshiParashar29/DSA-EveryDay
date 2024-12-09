/* Time Complexity : O(2^n) && Space Complexity : O(n)
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        return fib(n - 1) + fib(n - 2);
    }
};
