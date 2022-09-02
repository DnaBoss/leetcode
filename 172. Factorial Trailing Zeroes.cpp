/* an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

 

Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Example 3:

Input: n = 0
Output: 0
 

Constraints:

0 <= n <= 104
 

Follow up: Could you write a solution that works in logarithmic time complexity?
*/
#include<math.h> 
main(){
class Solution {
public:
    int trailingZeroes(int n) {
         if(n < 5) return 0 ;
         int count = 0;
            // 算階層內有幾個5出現
         while(n >= 5){
            count += floor(n/5);
            n = trunc(n/5);
         }

         return count;
    }
};
Solution s = new Solution()
s->trailingZeroes(500000)
}

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Factorial Trailing Zeroes.
// Memory Usage: 5.9 MB, less than 30.42% of C++ online submissions for Factorial Trailing Zeroes.