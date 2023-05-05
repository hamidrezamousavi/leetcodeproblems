class Node{
  public:
  int val{0};
  Node* next{nullptr};
  Node* prve{nullptr};
};
class MyLinkedList {
  Node* head;
  int len{0};  
public:
  MyLinkedList() {
    head = nullptr;  

  }

  int get(int index) {
    if(index > len - 1){
      return -1;
    }
    Node* tempHead{head};
    for(int i {0}; i < index; i++){
      tempHead = tempHead->next;
    }
    return tempHead->val;

  }

  void addAtHead(int val) {
    len++;
    Node* node = new Node{};
    node->val = val; 
    if(len == 1){
      head = node;
      return;
    }
    node->next = head;
    node->next->prve = node;
    head = node;
    return;
   }

  void addAtTail(int val) {
    len++;
    Node* node = new Node{};
    node->val = val; 
    if(len == 1){
      head = node;
      return;
    }
    Node* tempHead{head};
    for(int i {0}; i < len-2; i++){
      tempHead = tempHead->next;
    }
    tempHead->next = node;
    node->prve = tempHead;
    return;
  
  } 
  void addAtIndex(int index, int val) {
    if(index == 0){
      addAtHead(val);
      return;
    }
   if(index > len){
      return;
    }
    if(index == len){
      addAtTail(val);
      return;
    }
    len++;
    Node* node = new Node{};
    node->val = val;
    Node* tempHead{head};
    for(int i {0}; i < index; i++){
      tempHead = tempHead->next;
    }
    node->next = tempHead;
    node->prve = tempHead->prve;
    tempHead->prve->next = node;
    tempHead->prve = node;
    return; 
    

  }

  void deleteAtIndex(int index) {
    if(len == 0 || index > len-1){
      return;
    }
    if(index == 0){
      head = head->next;
      len--;
      return;
    }
    if(index == len-1){
      Node* tempHead{head};
      for(int i {0}; i < len-2; i++){
       tempHead = tempHead->next;
      }
      tempHead->next = {nullptr};
      len--;
      return;

    }
    Node* tempHead{head};
    for(int i {0}; i < index; i++){
      tempHead = tempHead->next;
    }
    tempHead->prve->next = tempHead->next;
    tempHead->next->prve = tempHead->prve;
    len--;
    return;

  }
};