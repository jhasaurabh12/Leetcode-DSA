/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */



/*
Approach-1:

Doing the level order on tree and for each level will be calculating the sum and storing it in the same variable. At the end, the variable will be containing the sum of last level processed and that will be the answer.

TC:O(n), SC:O(n)

*/

/*
Approach 2:

We will be doing the preorder/inorder traversal of the tree and we will keep track of maxDepth and maxDepthSum.

maxDepth: it stores the maximum depth so far in the traversal
maxDepthSum: it will store the sum of nodes at maxDepth height

->If we encounter a node which has depth greater than maxDepth, then maxDepth will be updated and maxDepthSum will be equal to current Node value.

->If we encounter a node whose depth is equal to maxDepth, then we simply increment the maxDepthSum by current node value

->IF we encounter a node whose depth is less than maxDepth, we do nothing

TC:O(N), SC:O(height of tree)

*/



class Solution {
    
public:
    
    void inorder(TreeNode* root,int &maxDepth, int &maxDepthSum, int curr){
        if(root==NULL)
            return;
        
        inorder(root->left,maxDepth,maxDepthSum,curr+1);
        if(curr==maxDepth){
            maxDepthSum+=root->val;
        }
        else if(curr>maxDepth){
            maxDepthSum=root->val;
            maxDepth=curr;
        }
        inorder(root->right,maxDepth,maxDepthSum,curr+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        int maxDepth=0,maxDepthSum=0;
        inorder(root,maxDepth,maxDepthSum,0);
        return maxDepthSum;
    }
};