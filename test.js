
function coinChange(coins, amount) { 
    let dp = [];
    const max = Number.MAX_SAFE_INTEGER;
    dp[0] = 0;
    for (i = 1; i <= amount; i++)dp[i] = max;
    for (i = 1; i <= amount; i++) { 
        coins.forEach(coin => {
            if (i - coin >= 0 && dp[i-coin] != max) { 
                dp[i] = Math.max(dp[i],dp[i-coin]+1)
            }
        });
    }

    return dp[amount];

}































// class TreeNode {
//     constructor(val, left, right) {
//         this.val = (val === undefined ? 0 : val)
//         this.left = (left === undefined ? null : left)
//         this.right = (right === undefined ? null : right)
//     }
// }
// function buildTreeBFS(arr) {
//     let q = [];
//     const val = arr.shift();
//     if (!val) return null;

//     const root = new TreeNode(val);
//     q.push(root);
//     while (q.length != 0) {
//         const node = q.shift();
//         let val = arr.shift();
//         if (val) {
//             node.left = new TreeNode(val);
//             q.push(node.left);
//         }
//         val = arr.shift();
//         if (val) {
//             node.right = new TreeNode(val);
//             q.push(node.right);
//         }
//     }
//     return root;
// }
// function buildTreePreOrder(arr) {
//     const val = arr.shift();
//     if (val) {
//         const node = new TreeNode(val);
//         node.left = buildTreePreOrder(arr);
//         node.right = buildTreePreOrder(arr);
//         return node;
//     } else {
//         return new TreeNode();
//     }
// }




// function lowestCommonAncestor(root, p, q) {
//     ancestor = root;
//     dfs(root, p, q);
//     return ancestor;
// }

// function dfs(root, p, q) {
//     if (!root) return false;
//     const isSelfAncestor = root.val == p.val || root.val == q.val;
//     const isInL = dfs(root.left, p, q);
//     const isInR = dfs(root.right, p, q);
//     if (isInL && isInR || isSelfAncestor && isInL || isSelfAncestor && isInR) {
//         ancestor = root;
//     }
//     return isSelfAncestor||isInL||isInR;
// }
// let arr = [5, 3, 6, 2, 4, null, null, 1]//[6, 2, 8, 0, 4, 7, 9, null, null, 3, 5];
// let tree = buildTreeBFS(arr);
// const a = lowestCommonAncestor(tree, new TreeNode(1), new TreeNode(4));
// console.log('a =', a.val);