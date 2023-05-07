#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

stack<int>* getNumberStack(ListNode*n){
  stack<int>* numberStack {new stack<int>};
  do{
    numberStack->push(n->val);
    n = n->next;
  }while(n);
  return numberStack;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  stack<int>* l1Stack = getNumberStack(l1);
  stack<int>* l2Stack = getNumberStack(l2);
  int temp{0};
  ListNode* result = nullptr;
      
  while(!(l1Stack->empty() && l2Stack->empty())){
    int n{0};
    int m{0};
    
    if(!l1Stack->empty()){
      n = l1Stack->top();
      l1Stack->pop();
    }
  
    if(!l2Stack->empty()){
      m = l2Stack->top();
      l2Stack->pop();
    }
    ListNode* node = new ListNode;
    node->val = (n + m + temp)%10;
    temp  = ((n + m + temp)>=10)?1:0;
    if(!result){
      result = node;
    }else{
      node -> next = result;
      result = node;
    }
 }
  if(temp == 1){
    ListNode* node = new ListNode;
    node->val = 1;
    node -> next = result;
    result = node;
    }
  return result;        
}
int main(){
  ListNode n4 = ListNode(4);
  ListNode n3 = ListNode(5,&n4);
  ListNode n2 = ListNode(7,&n3);
  ListNode n1 = ListNode(9,&n2);

  
  ListNode m3 = ListNode(6);
  ListNode m2 = ListNode(6,&m3);
  ListNode m1 = ListNode(9,&m2);
  
  
  auto result = addTwoNumbers(&n1, &m1);
  while(result->next){
    cout << result->val;
    result = result ->next;
  }
  cout << result->val<<endl;
  

}