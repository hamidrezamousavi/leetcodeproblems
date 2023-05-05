class Solution {
public:
    bool repeatedSubstringPattern(string s) {
      int sublen{1};
      int moveIndex{1};
      while(moveIndex + sublen <= s.size() ){
        while (true){
          if( s.substr(0,sublen) !=
              s.substr(moveIndex ,sublen))
            break;
          else{
            if(moveIndex + sublen == s.size())
              return true;
            moveIndex += sublen;
            if(moveIndex + sublen > s.size())
              break;
          } 
        }
      sublen++;
      moveIndex = sublen; 
      } 
    return false; 
    }
};