class MyCircularQueue {
private:
  vector<int> container;
  int len{0};
public:
    MyCircularQueue(int k) {
      len = k;
      container = {};
    }
    
    bool enQueue(int value) {
      if(container.size() < len){
        container.push_back(value);
        return true;
      }
      return false;
    }
    
    bool deQueue() {
      if(container.size()!= 0){
        container.erase(container.begin());
        return true;
      }
      return false;
        
    }
    
    int Front() {
      if(container.size() == 0){
        return -1;
      }
      return container[0];
    }
    
    int Rear() {
      if(container.size() == 0){
        return -1;
      }
      return container.back();
        
    }
    
    bool isEmpty() {
      return container.size() == 0;
    }
    
    bool isFull() {
      return container.size() == len;
        
    }
};


/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */