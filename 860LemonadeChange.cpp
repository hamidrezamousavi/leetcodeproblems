#include<vector>
#include<iostream>
using namespace std;
struct Coffer{
  int five{0};
  int ten{0};
};
bool isChangeable(int bill, const Coffer& coffer){
  switch(bill){
    case 5:
      return true;
    case 10:
      if(coffer.five > 0)
        return true;
      else
        return false;
    case 20:
      if(coffer.five > 2 || (coffer.five > 0 && 
                              coffer.ten > 0))
        return true;
      else
        return false;
  }
  return false;
}
void chage(int bill, Coffer& coffer){
  switch (bill){
    case 5:
      coffer.five++;
      break;
    case 10:
      coffer.five--;
      coffer.ten++;
      break;
    case 20:
      if(coffer.ten > 0){
        coffer.ten--;
        coffer.five--;
      }else{
        coffer.five -= 3;
      }
  }
}
bool lemonadeChange(vector<int>& bills) {
  Coffer coffer{};
  for(int bill:bills){
    cout << coffer.five <<','<< coffer.ten<<endl;
    if(!isChangeable(bill, coffer))
      return false;
    chage(bill, coffer);
    cout << coffer.five <<','<< coffer.ten<<endl;
    cout << "-------"<<endl;
  }
  return true;        

}

int main(){
  vector<int> bills {5,5,5,10,20};
  cout << lemonadeChange(bills);
}