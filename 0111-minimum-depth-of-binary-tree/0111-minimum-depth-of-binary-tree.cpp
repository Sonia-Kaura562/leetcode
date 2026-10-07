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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int ans = 1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                TreeNode* temp = q.front();
                q.pop();
                if(!temp->left && !temp->right) {
                    return ans;
                }
                else if(temp->left && temp->right) {
                    q.push(temp->left);
                    q.push(temp->right);
                }
                else if (temp->left){
                    q.push(temp->left);
                }
                else {
                    q.push(temp->right); 
                }
            }
            ans++;
        }
        return ans;
    }
};