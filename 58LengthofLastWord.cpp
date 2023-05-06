class Solution {
public:
  int lengthOfLastWord(string s) {
    bool skip= true;
    int lengthOfLast{0};
    for(auto ch{s.rbegin()}; ch < s.rend(); ch++){
      
      if(*ch == ' ' && skip){
        continue;
      }
      if(*ch ==' ' )
        break;
      skip = false;
      lengthOfLast++;
      
      
    }
    return lengthOfLast;
          
      }
};