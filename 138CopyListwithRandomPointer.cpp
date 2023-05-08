#include <map>
#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val,Node* next, Node* random) {
        val = _val;
        this->next = next;
        this->random = random;
    }
};


Node* copyRandomList(Node* head) {
  map<Node*, Node*> nodesMap{};
  Node* temp = head;
  while(temp){
    Node* newNode = new Node(temp->val, nullptr, nullptr);
    nodesMap[temp] = newNode;
    temp = temp -> next;
  }
  for(auto item:nodesMap){
    item.second -> next = nodesMap[item.first->next];
    item.second -> random = nodesMap[item.first->random];
       
  }
  return nodesMap[head];        
}

int main(){
  map<Node*, Node*> nodesMap{};

  Node node4 = Node{1,nullptr,nullptr};
  Node node3{10,&node4,&node4};
  Node node2{11,&node3,nullptr};
  Node node1{13,&node2,&node3};
  Node node0{7, &node1, nullptr};
  Node* temp = &node0;
  auto node = copyRandomList(&node0);
  
  return 0;
}
