struct TreeNode {
* int val;
TreeNode left;
TreeNode right;
* TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
TreeNode convertBST(TreeNode root) {
int sum = 0;
postOrder(root, sum);
return root;
}
void postOrder(TreeNode* root, int& sum) {
if(root == NULL) return ;
postOrder(root->right, sum);
int val = root -> val;
root->val += sum; sum += val;
postOrder(root -> left, sum);
}
};