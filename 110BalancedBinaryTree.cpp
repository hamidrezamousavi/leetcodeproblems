class Solution {
public:
    int depthOfNode(TreeNode* node){
      if(!node)
        return -1;
      int  rdepth= depthOfNode(node->right); 
      int ldepth = depthOfNode(node->left);
      int depth = rdepth > ldepth?rdepth:ldepth;
      return depth + 1;
    }
    bool nodeBalance(TreeNode* node){
      if(!node)
        return true;
      if(abs(depthOfNode(node->right)-depthOfNode(node->left))< 2 &&
             nodeBalance(node->left)&& 
             nodeBalance(node->right)){
        return true;
             }
      return false;
    }
    bool isBalanced(TreeNode* root) {
        return nodeBalance(root);
    }
};