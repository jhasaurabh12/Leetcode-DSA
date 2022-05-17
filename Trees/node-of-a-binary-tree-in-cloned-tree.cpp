/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


/*
first question that comes to mind-> does trees have unique values. In this case we have, so we can simply traverse the cloned tree and whenever we find the node having value equal to target node's value we return that node;

Follow-up: If tree had duplicate values

we will simulatneously travel the both trees and whenever we reach target node in original tree, then we would have simulnateously reached that node in cloned tree and that node will be our answer

*/
class Solution {
public:
//------------first approach for no duplicate nodes present in tree--------
//     TreeNode* preorder(TreeNode* root, int val){
//         if(root==NULL)
//             return NULL;
        
//         if(root->val==val)
//             return root;
        
//         TreeNode* left=preorder(root->left,val);
        
//         if(left) 
//             return left;
        
//         TreeNode* right=preorder(root->right,val);
//         return right;
//     }
    
//------------second approach with duplicate nodes present in tree---------
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
             // return preorder(cloned,target->val);
        
            if(original==NULL)
                return NULL;
            if(original==target)
                return cloned;
        
            TreeNode* left=getTargetCopy(original->left,cloned->left,target);
            if(left)
                return left;
            TreeNode* right=getTargetCopy(original->right,cloned->right,target);
            return right;
    }
};