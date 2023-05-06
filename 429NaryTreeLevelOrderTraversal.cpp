/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
     
      vector<Node*> v1 {root};
      vector<Node*> v2;
      vector<vector<int>> result;
      vector<int> temp;
      if(!root){
        return result;
      }
      while(!v1.empty()){
        for(auto node:v1){
          temp.push_back(node->val);
          for(auto nod:node->children){
            v2.push_back(nod);
          }
        }
        result.push_back(temp);
        v1 = v2;
        temp.erase(temp.begin(),temp.end());
        v2.erase(v2.begin(), v2.end());
      }
      return result;
    }
};