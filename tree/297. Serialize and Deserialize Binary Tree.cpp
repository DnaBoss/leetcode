/*
Serialization is the process of converting a data structure
 or object into a sequence of bits 
 so that it can be stored in a file or memory buffer, 
or transmitted across a network connection link 
to be reconstructed later in the same 
or another computer environment.

Design an algorithm to serialize 
and deserialize a binary tree. 
There is no restriction on 
how your serialization/deserialization algorithm should work. 
You just need to ensure that a binary tree 
can be serialized to a string 
and this string can be deserialized 
to the original tree structure.

Clarification: The input/output format 
is the same as how LeetCode serializes a binary tree. 
You do not necessarily need to follow this format, 
so please be creative 
and come up with different approaches yourself.

Example 1:
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
Output: []

題意:完成二個方法，序列化及反序列化
第一個方法:給一個樹，把它序列化成一個字串
第二個方法:把這個字串轉成一顆樹
(要跟原來的樹一模一樣)
序列化的演算法愛怎麼寫都可以

思路:
序列化:用bfs，把節點一個一個存到字串，空節點隨便用一個字元代替
反序列化:用bfs及stringstream分割字串
只要知道，每一個節點的子節點，在這個序列化字串中，都會緊跟在其後

用dfs 也可以，只是要記得，怎麼放進去的就要怎麼拿出來
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        queue<TreeNode*>q;
        q.push(root);
        string s;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == nullptr){
                s+="n ";
            }else{
                s +=to_string(node->val)+" ";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return nullptr;
        stringstream ss;
        ss << data;
        string cur;
        ss >> cur;
        queue<TreeNode*>q;
        TreeNode* root = new TreeNode(stoi(cur));
        q.push(root);
        
        while(!q.empty()){
           TreeNode* node = q.front();
           q.pop();
            ss >> cur;
            if(cur!="n"){
                node->left = new TreeNode(stoi(cur)); 
                q.push(node->left);
            }
            ss >> cur;
            if(cur!="n"){
                node->right = new TreeNode(stoi(cur)); 
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

// Runtime 105 ms Beats 57.25% Memory 29.3 MB Beats 63.81%