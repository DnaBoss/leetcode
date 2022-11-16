
/*
Given an n-ary tree, return the level order 
traversal of its nodes' values.
Nary-Tree input serialization is represented in their level order traversal, 
each group of children is separated by the null value (See examples).

Example 1:
Input: root = [1,null,3,2,4,null,5,6]
Output: [[1],[3,2,4],[5,6]]

Example 2:
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
題意:用bfs歷遍n叉樹
思路:在bfs 的for 迴圈中 再加入一個 children 的迴圈，把每一個節點加進q
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> vvi;
        if(!root)return vvi;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>vi;
            for(int i =0;i<size;i++){
                Node* node = q.front();
                q.pop();
                vi.push_back(node->val);
                vector<Node*> children = node->children;
                int cSize = children.size();
                for(int j=0;j<cSize;j++){
                    q.push(children[j]);
                }
            }
            vvi.push_back(vi);
        }
        return vvi;
    }
};
// Runtime 62 ms Beats 16.65% Memory 12.1 MB Beats 7.54%