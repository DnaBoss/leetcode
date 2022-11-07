/*
You are given a perfect binary tree 
where all leaves are on the same level, 
and every parent has two children. 
The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer 
to point to its next right node. 
If there is no next right node, 
the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

Example 1:
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

題目:給一顆完美二元樹，把每一層的節點用鏈結串列串起來
讓每一個節點的next 都是它同一層的右邊節點
思路:用 queue 跟bfs遍歷 用queue.front 拿出同層的下個節點
注意最後一個節點不能做這個操作，也不用刻意給最右邊的節點null，因為本來就是null
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                Node* node = q.front();
                q.pop();
                if(i<size-1)node->next = q.front();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        return root;
    }
};

// Runtime 37 ms Beats 64.93% Memory 17.1 MB Beats 54.27%