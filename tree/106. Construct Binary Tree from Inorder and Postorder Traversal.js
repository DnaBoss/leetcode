
/**
題目:Given inorder and postorder traversal of a tree, construct the binary tree.
題意:給定 中序及後序訪問一顆樹的陣列，還原這顆樹
思路:抄105題的即可，前序改後序而己，
重點還是一樣，中序最中的數字是root，
的左邊是左子樹，右邊是右子樹
後序的最後一個數字是根

 * @param {number[]} inorder
 * @param {number[]} postorder
 * @return {TreeNode}
 */
function buildTree(inorder, postorder) {
    return builder(inorder, postorder, 0, inorder.length - 1, 0, postorder.length - 1);
}

function builder(inorder, postorder, inMin, inMax, postMin, postMax) {
    // 邊界判定
    if (inMin > inMax || postMin > postMax) {
        return null;
    }
    let rootVal = postorder[postMax];
    let node = new TreeNode(rootVal);
    // 找出根值在中序中的位置 i 
    for (let i = inMin; i <= inMax; i++) {
        if (inorder[i] == rootVal) {
            // 找左子節點
            node.left = builder(inorder, postorder, inMin, i - 1, postMin, postMin + i - inMin - 1);
            // 找右子節點
            node.right = builder(inorder, postorder, i + 1, inMax, postMin + i - inMin, postMax - 1);
            break;
        }
    }
    return node;
}

class TreeNode {
    constructor(val, left, right) {
        this.val = (val === undefined ? 0 : val)
        this.left = (left === undefined ? null : left)
        this.right = (right === undefined ? null : right)
    }
}