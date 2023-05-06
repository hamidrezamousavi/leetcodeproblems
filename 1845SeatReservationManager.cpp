#include<set>
#include<iostream>
using namespace std;

class SeatManager {
 int capacity;
 set<int> unreserveSeat;
public:
    SeatManager(int n) {
      capacity = n;
      for(int i{1}; i<= n; i++)
        unreserveSeat.insert(i);  
    }
    
    int reserve() {
      int seat = *unreserveSeat.begin();
      unreserveSeat.erase(seat);
      return seat;
    }
    
    void unreserve(int seatNumber) {
        unreserveSeat.insert(seatNumber);
    }
};

int main(){
  SeatManager* obj = new SeatManager(10);
  int param_1 = obj->reserve();
  int param_2 = obj->reserve();
  int param_3 = obj->reserve();
  obj->unreserve(2);
  cout << obj->reserve();
  return 0;
}