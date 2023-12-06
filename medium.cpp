//Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

#include <iostream>
#include <queue>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to find the lowest common ancestor in a BST
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* r=root;
    while(true){
        if(r->val==p->val){
            return p; 
            break;
        }
        if(r->val==q->val){
            return q; 
            break;
        }
        else if(((r->val)>(p->val) && r->val<q->val) || ((r->val)<(p->val) && (r->val)>(q->val))){
            return r; 
            break;
        }
        else if(r->val>p->val && r->val>q->val){
            r=r->left;
        }
        else{
            r=r->right;
        }
    }
}


int main() {
    // Constructing the BST: [6,2,8,0,4,7,9,null,null,3,5]
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    TreeNode* p = root->left;  // Node with value 2
    TreeNode* q = root->right; // Node with value 8

    TreeNode* result = lowestCommonAncestor(root, p, q);

    if (result) {
        std::cout << "Lowest Common Ancestor: " << result->val << std::endl;
    } else {
        std::cout << "Nodes not found in the BST." << std::endl;
    }

    // free the allocated memory
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
