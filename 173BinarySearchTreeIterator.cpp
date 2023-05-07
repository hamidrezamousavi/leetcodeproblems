#include<stack>
#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
private:
stack<TreeNode*> leftStack;
TreeNode* root;

void getLeftStack(TreeNode* node){
  while(node->left){
    leftStack.push(node);
    node = node->left;
  }
  leftStack.push(node);
}  
public:
BSTIterator(TreeNode* root) {
  getLeftStack(root);
  this->root = leftStack.top();
}

int next() {
  int nextVal = leftStack.top()->val;
  if(leftStack.top()->right){
    auto tempNode = leftStack.top();
    leftStack.pop();
    getLeftStack(tempNode->right);
  }else{
      leftStack.pop();
  }
  return nextVal;  
}

bool hasNext() {
  return leftStack.size();   
}
};

int main(){
TreeNode node13{22,nullptr,nullptr};
TreeNode node12{9,nullptr,nullptr};
TreeNode node10{12,nullptr,nullptr};
TreeNode node11{23,&node13,nullptr};
TreeNode node6{16,nullptr,nullptr};
TreeNode node7{25,&node11,nullptr};
TreeNode node8{4,nullptr,nullptr};
TreeNode node9{10,&node12,nullptr};
TreeNode node3{20,&node6,&node7};
TreeNode node4{5,&node8,nullptr};
TreeNode node5{11,&node9,&node10};
TreeNode node2{8,&node4,&node5};
TreeNode node1{15,&node2,&node3};

BSTIterator bs(&node1);

cout << bs.next()<< endl;
cout << bs.hasNext()<< endl;
cout << bs.next()<< endl;
cout << bs.next()<< endl;
cout << bs.next()<< endl;
cout << bs.next()<< endl;
cout << bs.next()<< endl;
cout << bs.next()<< endl;
cout << bs.next()<< endl;
cout << bs.next()<< endl;
cout << bs.next()<< endl;
cout << bs.next()<< endl;
cout << bs.next()<< endl;
cout << bs.next()<< endl;
cout << bs.hasNext()<< endl;
return 0;
}