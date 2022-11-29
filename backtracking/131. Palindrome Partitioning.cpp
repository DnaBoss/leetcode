/*
題目:https://leetcode.com/problems/palindrome-partitioning/description/
題意:把一個字串，切割成若干個子字串，將可以成為回文的子字串，返回所有的組合
*/

class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;
    vector<vector<string>> partition(string s) {
        backtracking(s,0);
        return result;
    }
    void backtracking(const string& s,int startIndex){
 
        int size = s.size();
        if(startIndex == size){
            result.push_back(path);
            return;
        }

        for(int i = startIndex; i< size; i++){
            if(isPalindrome(s,startIndex,i)){
                string str = s.substr(startIndex,i-startIndex+1);
                path.push_back(str);
                backtracking(s,i+1);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(const string& s,int start,int end){
        for(int i = start,j = end;i < end; i++,j--){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }
};

// Runtime 116 ms Beats 94.85% Memory 75.7 MB Beats 37.47%