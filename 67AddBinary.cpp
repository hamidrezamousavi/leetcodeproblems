#include <algorithm>

class Solution {
public:
    string addBinary(string a, string b) {
        int size = (a.size() > b.size())?a.size():b.size();
    char num1{'0'};
    char num2{'0'};
    char temp{'0'};
    string result{};
    for(int i{1}; i <= size ; i++){
      if (i <= a.size())
        num1 = a[a.size()-i];
      else 
        num1 = '0';
      if (i <= b.size())
        num2 = b[b.size()-i];
      else 
        num2 = '0';

    
      switch (num1 + num2 + temp){
        case '1'+'1'+'1':
          temp = '1';
          result += '1';
          break;
        case '1'+'1'+'0':
          temp = '1';
          result += '0';
          break;
        case '1'+'0'+'0':
          temp = '0';
          result += '1';
          break;
        case '0'+'0'+'0':
          temp = '0';
          result += '0';
          break;  
        
        
      }
    }
    if (temp == '1'){
      result += '1';
    }
    reverse(result.begin(), result.end());
    return result;
    }
};