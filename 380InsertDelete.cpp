#include <set>
#include <random>
using namespace std;
class RandomizedSet {
  set<int> container;
  mt19937 class_gen;
private:
  
public:
    RandomizedSet() {
      
      random_device rd;  
      class_gen.seed(rd());
  
    }
    
    bool insert(int val) {
      return container.insert(val).second;    
    }
    
    bool remove(int val) {
      return container.erase(val);
    }
    
    int getRandom() {
      uniform_int_distribution<> distrib(0,container.size()-1);
      return *next(container.begin(),distrib(class_gen));
    }
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */