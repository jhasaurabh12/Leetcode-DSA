#include<bits/stdc++.h>
using namespace std;


void IPPTraversal(TreeNode* root){
    vector<int> preorder,inorder,postorder;

    TreeNode* curr=root;
    TreeNode* prev=NULL;
    stack<TreeNode*> st;

    while(curr!=NULL || !st.empty()){
        if(curr!=NULL){
            preorder.push_back(curr->val);
            st.push(curr);
            curr=curr->left;
        }
        else{
            auto temp=st.top();
            if(temp->right==NULL){
                inorder.push_back(temp->val);
                postorder.push_back(temp->val);
                prev=temp;
                st.pop();
            }
            else if(temp->right==prev){
                postorder.push_back(temp->val);
                prev=temp;
                st.pop();
            }
            else{
                inorder.push_back(temp->val);
                curr=temp->right;
            }
        }
    }

}
int main(){
    return 0;
}