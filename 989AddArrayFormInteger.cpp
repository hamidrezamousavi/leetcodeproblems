class Solution {
public:
  int toInt(vector<int>& num){
    int ans{0};
    int order{1};
    for(int i=num.size()-1; i >= 0; i--){
      ans += num[i] * order;
      order *= 10;
    }
    return ans;
  }
  vector<int> toVec(int num){
    vector<int> ans{};
    while(num){
     int c = num % 10;
     ans.insert(ans.begin(),c); 
     num = (num - c)/10;
    }
    return ans;
  }
  vector<int> addToArrayForm(vector<int>& num, int k) {
    vector<int> kVec{toVec(k)};
    int len = num.size() > kVec.size()? num.size():kVec.size();
    vector<int> ans(len,0);

    if(num.size() > kVec.size()){
      vector<int> zero(num.size()- kVec.size(), 0);
      kVec.insert(kVec.begin(), zero.begin(), zero.end());
    }
    if(num.size() < kVec.size()){
      vector<int> zero(kVec.size()- num.size(), 0);
      num.insert(num.begin(), zero.begin(), zero.end());
    }
    int temp {0};
  
    for(int i{len -1}; i >= 0; i--){
      ans[i] = (num[i] + kVec[i]+ temp) % 10;
      temp = (num[i] + kVec[i]+ temp >= 10)?1:0;
    }
    if(temp)
      ans.insert(ans.begin(),temp);
    return ans;
  }
};