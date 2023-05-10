#include<vector>
class NumMatrix{
  vector<vector<int>> data{};
  vector<vector<int>> squrSum{};
 
public:
  NumMatrix(vector<vector<int>>& matrix) {
    
    for(int i{0}; i < matrix.size(); i++){
      squrSum.push_back(vector<int>(matrix[0].size(),0));
    }
    squrSum[0][0] = matrix[0][0];
    for(int col{1}; col < squrSum[0].size(); col++){
      squrSum[0][col] = matrix[0][col]+ squrSum[0][col-1];
    }
    int temp {0};
    for(int row{1}; row < squrSum.size(); row++){
      for(int col{0}; col < squrSum[0].size(); col++){
        temp += matrix[row][col];
        squrSum[row][col] = temp + squrSum[row-1][col];
      }
      temp = 0;
    }
  }
    
  int sumRegion(int row1, int col1, int row2, int col2) {
    if (row1 == 0 && col1 == 0)
      return squrSum[row2][col2];
    if(row1 == 0)
      return squrSum[row2][col2] - squrSum[row2][col1-1];
    if(col1 == 0 )
      return squrSum[row2][col2] - squrSum[row1-1][col2];
        
    return squrSum[row2][col2]+squrSum[row1-1][col1-1] - 
           squrSum[row1-1][col2] - squrSum[row2][col1-1];
  }
};
