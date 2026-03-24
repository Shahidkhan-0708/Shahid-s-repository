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
vector<vector<int>>large(TreeNode* root,int k,int sum,vector<int>& small,vector<vector<int>>& ans){
   if(root==NULL){
    return ans;
   }
   small.push_back(root->val);
   sum+=root->val;
   if(sum==k&&root->left==NULL&&root->right==NULL){
    ans.push_back(small);
   }
   large(root->left,k,sum,small,ans);
   large(root->right,k,sum,small,ans);
   small.pop_back();
   return ans;
   }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<int>small;
    vector<vector<int>>ans;
    vector<vector<int>>big=large(root,targetSum,0,small,ans);
    return big;

    }
};