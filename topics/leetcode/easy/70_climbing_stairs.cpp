#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {

        // for 1 step, there's 1 way to climb to the top
        // for 2 steps, there' 2 ways (1 + 1 or 2)

        // for n steps, we can reach to the n'th step from 
        // either the (n-1)'th step or from the (n-2)'th step
        // there is no other way.

        // what this means is that climbStairs(n) = climbStairs(n-1) + climbStairs(n-2).
        // this is because we can climb the steps in climbStairs(n-1) distinct ways to reach 
        // the (n-1)'th stair and climbStairs(n-2) distinct ways to reach the (n-2)'th stair.
        // from there on take 1 or 2 steps, getting to the n'th step. hence we have a recursive relation.

        // a naive recursive approach would be as shown in the function below.
        // explanation for why this is bad is in the function.

        // a better approach is to use dynamic programming.

        if (n <= 2) return n; // base case
        
        vector<int> dp(n);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n-1];
    }

    int spaceEfficient(int n) {
        // can also have a space efficient version
        // this is better than using an array, unless we want to keep the array global and use it as a cache
        // that is known as tabulation.
        if (n<=2) return n;
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++) {
            int temp = first + second;
            first = second;
            second = temp;
        }
        return second;
    }

    int naiveRecursion(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        return climbStairs(n-1) + climbStairs(n-2);

        // this is bad because the time complexity becomes 2^n
        // each recursive call makes 2 more recursive calls.
        // that is, we create a full binary tree with height n:

        //        n
        //     /     \
        //   n-1     n-2
        //  /   \    /   \
        // ...
        // 1   1   1 ...  1

        // not only can this lead to a stack overflow, it is very inefficient.
        // moreover, we are recalculating the same values multiple times.
    }
};