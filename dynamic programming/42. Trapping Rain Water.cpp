/*
42. Trapping Rain Water
Hard
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105

*/

/*
測資不過
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int ans = 0;
        for(int i = 0;i<size-1;i++){
            int max_left = 0,max_right=0;
            for(int j =i;j<size;j++){
                max_right = max(max_right,height[j]);
            }
            for(int j =i;j>=0;j--){
                max_left = max(max_left,height[j]);
            }
            ans +=  min(max_left,max_right) - height[i];
        }
        return ans;
    }
};
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> max_right(size),max_left(size);
        max_left[0] = height[0];
        // 從左往右走
        for(int i = 1; i< size ; i++){
            max_left[i] = max(max_left[i-1],height[i]);
        }
        max_right[size-1] = height[size-1];
        // 從右往左走
        for(int i = size-2; i >= 0 ; i--){
            max_right[i] = max(max_right[i+1],height[i]);
        }
        int ans = 0;
        for(int i = 0; i< size-1 ; i++){
            ans += min(max_left[i], max_right[i] ) - height[i];
        }
        return ans;
    }
};

// 执行用时：8 ms, 在所有 C++ 提交中击败了92.81%的用户
// 内存消耗：19.9 MB, 在所有 C++ 提交中击败了7.65%的用户
// 通过测试用例：322 / 322