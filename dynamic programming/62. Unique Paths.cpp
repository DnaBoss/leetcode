/*62. Unique Paths
Medium

8946

299

Add to List

Share
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.
Example 1:


Input: m = 3, n = 7
Output: 28

Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down


Constraints:

1 <= m, n <= 100
Accepted
947,017
Submissions
1,572,698
*/

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int dp[m][n];
        for (int x = 0; x < m; x++)
            dp[x][0] = 1;
        for (int y = 0; y < n; y++)
            dp[0][y] = 1;
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths.
// Memory Usage: 5.8 MB, less than 91.08% of C++ online submissions for Unique Paths.

/*
效能較差，但較易理解版本，使用unordered_map會比 map 效能好很多，差異頗大
using namespace std;

class Solution
{
public:

    int uniquePaths(int m, int n)
    {

        return fn(m, n);
    }

    int fn(int m, int n)
    {
        if (m < 0 || n < 0)
            return 0;
        if (m == 1 || n == 1)
            return 1;
        if (dp[m][n] != 0)
            return dp[m][n];
        int left_path = fn(m - 1, n);
        int top_path = fn(m, n - 1);
        dp[m][n] = left_path + top_path;
        return dp[m][n];
    }
private:
    std::unordered_map<int, std::unordered_map<int, int> > dp;
};

使用map
Runtime: 12 ms, faster than 5.80% of C++ online submissions for Unique Paths.
Memory Usage: 8.3 MB, less than 26.35% of C++ online submissions for Unique Paths.

使用unordered_map
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths.
Memory Usage: 8.5 MB, less than 26.35% of C++ online submissions for Unique Paths.
*/