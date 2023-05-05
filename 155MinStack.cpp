#include <vector>
#include <map>
#include <iostream>
using namespace std;
class MinStack {
  vector<int> stack;
  map<int, int> minMap;
  
public:
    MinStack() {
      stack = {};  
      minMap = {};  
    }
    
    void push(int val) {
       
        stack.push_back(val);
        minMap[val]++;
    }
    
    void pop() {
       
      minMap[stack.back()]--;
      
      if(!minMap[stack.back()] ){
        
        minMap.erase(stack.back());

      }
     
      stack.pop_back();
      
        
    }
    
    int top() {
      return stack[stack.size()-1];
        
    }
    
    int getMin() {
        return minMap.begin()->first;
    }
};
int main(){
  MinStack* obj = new MinStack();
  obj->push(10);
  obj->push(9);
  obj->push(7);
  obj->pop();
  cout << obj->top()<<endl;
  cout << obj->getMin();
  return 0;
  
}