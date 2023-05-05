/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool invest(TreeNode* node, ListNode* head){
      if(!head)
        return true;
      if(!node)
        return false;
      if(head->val == node->val){
        head = head -> next;
        return invest(node->left, head) || 
               invest(node->right, head);
      }
      return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
      if( invest(root, head))
        return true;
      if(!root)
        return false;
      return isSubPath(head, root->left)||
             isSubPath(head, root->right); 
    }
     
};