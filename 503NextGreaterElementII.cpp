class Solution {
public:
  int find_next(vector<int>& nums, int num, int idx){
    for(int i{idx}; i<nums.size(); i++){
      if(nums[i]> num)
        return nums[i];
    }
    for(int i{0}; i< idx; i++)
      if(nums[i]> num)
        return nums[i];
    return -1;
  }
vector<int> nextGreaterElements(vector<int>& nums) {
     vector<int> result{};
     for(int i{0}; i<nums.size() ; i++){
      result.push_back(find_next(nums,nums[i],i));
     }
     return result;   
 }
};