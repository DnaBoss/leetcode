/*
題目:https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
題意:字串blocks 裡，要湊出 k 個連續的 B，最少需要幾個W
思路:滑窗，首先建立一個字串區塊，長度為K，
計算區塊中有多少W
每往右移動一格，如果K區塊有W 就 減少W的數量，
往右移的那個字元如果有W，就加上W的數量
然後就視為滑窗移動一格
去計算滑窗從頭走到尾，出現W最少的那個時後，W 的數量是多少
*/

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int mid = count(blocks.begin(),blocks.begin() + k,'W');
        int res = mid;
        for(int i = k; i < blocks.size(); i++){
            if(blocks[i - k] == 'W')mid--;
            if(blocks[i] == 'W')mid++;
            res = min(res,mid);
        }
        return res;
    }
};