https://leetcode.com/problems/range-sum-of-bst/

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
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) 
    {
        int sum=0;
        sol(root,L,R,sum);
        return sum;
    }
    
    void sol(TreeNode* root, int L, int R,int &sum)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->val>=L&&root->val<=R)
        {
            sum+=root->val;
        }
        sol(root->right,L,R,sum);
        sol(root->left,L,R,sum);    
    }
};
