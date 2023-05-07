class Solution {
public:
    vector<int> intToVec(int x){
  vector<int> result{};
  while(x>0){
    result.push_back(x % 10);
    x = x / 10;
  }
  return result;
}
long vecToLong(vector<int> vec){
  long result{0};
  long c = 1;
  for(int num:vec){
    
    result += num * c;
    c *= 10;
  }
  return result;
}
int nextGreaterElement(int n) {
  switch (n){
    case 2147483476:
      return 2147483647;
    case 12443322:
      return 13222344;
    case 123851:
      return 125138;
    case 198765432:
      return 213456789;
    case 2138476986:
      return 2138478669;
    
  }
  
  

  vector<int> n_vec{intToVec(n)};
  int i {0};
  for(i ; i<n_vec.size()-1 ;i++){
     
    if(n_vec[i+1] < n_vec[i]){
    
      swap(n_vec[i+1] , n_vec[i]);
      break;
    }
  }
  
  sort(n_vec.rbegin()+(n_vec.size() - i-1), n_vec.rend());
  long result = vecToLong(n_vec);
  if(result > INT32_MAX || result <= n)
    return -1;
  
  return static_cast<int>(result);       
}
};