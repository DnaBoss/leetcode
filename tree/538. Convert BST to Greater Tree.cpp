/*
Given the root of a Binary Search Tree (BST), 
convert it to a Greater Tree such that every key 
of the original BST is changed to the original key plus 
the sum of all keys greater than the original key in BST.
As a reminder, a binary search tree is a tree that satisfies these constraints:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

題意:用右樹中序，走訪樹，把前一個節點的值，
加上當前節點的值，設為當前節點的新值
往下走訪，依此循環

思路: 
設一個 全域的節點，
用來記錄前一個節點，方便取得它的值
中序遍歷，但是先走右子樹
*/