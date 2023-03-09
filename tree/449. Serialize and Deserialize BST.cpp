/*
照抄 297題
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        queue<TreeNode*>q;
        q.push(root);-
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
      ˋ'|}}}}  queue<TreeNode*>q;/        TreeNode* root = new TreeNode(stoi(cur));
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
