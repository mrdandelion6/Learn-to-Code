#include<iostream>
using namespace std;
class Solution {
    public:
        int mySqrt(int x) {
            // first we will do a binary-search approach
            long long left = 1, right = x;
            while (left < right) {
                long long mid = left + (right - left+1) / 2;
                
                if (left*left <= x && (left+1)*(left+1) > x)
                    return left;
                if (mid*mid <= x && (mid+1)*(mid+1) > x)
                    return mid;
                if (right*right <= x && (right+1)*(right+1) > x)
                    return right;
                
                if (mid*mid < x)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            return right;
        }

        static int newtonRaphson(int x) {
            // the newton raphson method converges to the square root faster than binary search
            // we employ newton's method:
                // x_{n+1} = x_n - f(x_n) / f'(x_n)
            // this method approximates the root of f(x), i.e, as n -> inf, f(x_n) -> 0
            // we use f(n) = n^2 - x to model finding square root.
            // because f(n) = 0 => n^2 = x
            // so n - f(n) / f'(n) = n - (n^2 - x) / (2n)
            //                     = n - n/2 + x/(2n)
            //                     = n/2 + x/(2n)
            //                     = (n + x/n) / 2

            // instead of !(n*n <= x && (n+1)*(n+1) > x), which is valid, we can also use:
                // (n > x/n)
            // that is: n*n > x
            // this is because as soon as we find an n such that n*n <= x, this n satisfies being a ceiled root.
            // we do not ever overshoot under this value. sequence always converges downwards (trust me bro).

            if (x <= 1) return x;
            long long n = x/2 + 1;
            while ( n > x/n )
                n = (n + x/n) / 2;
            return n;

            // an important consideration:
            // if we use n = n - (n^2 - x) / (2*n) instead, it fails!
            // even though these are mathematically equivalent formulas, we are neglecting rounding!
            // integer division does flooring, and when we divide by 2*n, we are flooring harder 
            // for example, take x = 8 and guess n = 5
            // then:
                // n = (5 + 8/5) / 2
                // n = (5 + 1) / 2
                // n = 3

                // n = (3 + 8/3) / 2
                // n = 5 / 2
                // n = 2

                // works!

            // but for n - (n^2 - x) / (2*n):
                // n = 5 - (5^2 - 8) / (2*5)
                // n = 5 - 17/10
                // n = 4
                
                // n = 4 - (16 - 8) / (2*4)
                // n = 4 - 8/8
                // n = 3

                // n = 3 - (9 - 8) / (2*3)
                // n = 3 - 1/6
                // n = 3

                // now we get stuck at an infinite loop of n = 3 because (n^2 - x) / (2*n) gets rounded too hard.
                // this is a very peculiar consideration.
        }
};