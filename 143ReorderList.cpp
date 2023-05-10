#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void reorderList(ListNode* head) {
  vector<ListNode*> nodes{};
  while(head){
    nodes.push_back(head);
    head = head->next;
  }
  for(int i{0}; i< nodes.size()/2; i++){
    nodes[i]->next = nodes[nodes.size()-i-1];
  }
  
  for(int i{0};i<nodes.size()/2;i++){
    nodes[nodes.size()-i-1]->next = nodes[i+1];
  }
  nodes[nodes.size()/2]->next = nullptr;
        
}
int main(){
  ListNode node9{9, nullptr};
  ListNode node8{8, &node9};
  ListNode node7{7, &node8};
  ListNode node6{6, &node7};
  ListNode node5{5, &node6};
  ListNode node4{4, &node5};
  ListNode node3{3, &node4};
  ListNode node2{2, &node3};
  ListNode node1{1, &node2};
  reorderList(&node1);
  ListNode* head = &node1;
  while(head){
    cout << head->val<<',';
    head = head->next;
  }

}
