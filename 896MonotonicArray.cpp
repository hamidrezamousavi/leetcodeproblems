class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
      ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
      int g{0}, s{0};
      for(auto iter{nums.begin()}; iter < nums.end()-1; iter++){
        if(*iter == *(iter+1))
          continue;
        else if (*iter > *(iter+1))
          g++;
        else
          s++;
        if(s && g)
          return false;
      }
  
 
      return true;
        
    }
};