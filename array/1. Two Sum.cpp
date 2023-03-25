/**
 * @brief 
 * 題目:https://leetcode.com/problems/two-sum/description/
 * 題意:從數組中找出唯一的二個數字組合，剛好等於 target 
 * 思路:一個hash map 記錄出現過的數字，key 是數字 value 是 index
 * 
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            int index = target - nums[i];
            if(map.find(index) != map.end()){
                return vector<int>{map[index], i};
            }
            map[nums[i]] = i;
        }
        return vector<int>();
    }
};
