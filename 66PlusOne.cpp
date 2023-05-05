class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int temp{1};
        for(auto iter = digits.rbegin();iter != digits.rend(); iter++){
         temp = (*iter + temp);
         *iter = temp % 10;
         temp = (temp >= 10) ? 1 : 0;
        }
        if(temp == 1){
          digits.insert(digits.begin(), 1);
        }
    return digits;
        
    }
};