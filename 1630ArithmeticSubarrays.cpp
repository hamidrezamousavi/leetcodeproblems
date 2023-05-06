class Solution {
public:
  bool couldBeArithmetic(vector<int> nums ,int begin ,int end){
  
  sort(nums.begin()+begin, nums.begin()+end+1);
  int diff = nums[begin] - nums[begin+1];
  for(int i{begin}; i < end; i++){
    if(nums[i] - nums[i+1] != diff)
      return false;
    
  }
 
  return true;
}
vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    vector<bool> ans{};
    for(int i{0}; i < l.size(); i++){
      ans.push_back(couldBeArithmetic(nums , l[i], r[i]));
    }
        
  return ans;
}
};