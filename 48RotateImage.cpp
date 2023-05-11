 void rotateNth(vector<vector<int>>& matrix, int n){
  int rowBegin = n;
  int rowEnd = matrix.size()- n-1;
  int colBegin = n;
  int colEnd = matrix[0].size()-n-1;
  int ms = matrix.size();
for(int j{0};j< ms-n-1;j++){
  int temp = matrix[rowBegin ][colBegin];
for(int i{0}; i < ms-2*n-1; i++){
  matrix[rowBegin + i][colBegin] = matrix[rowBegin+i+1][colBegin]; 
}
for(int i{0};i < ms-2*n-1; i++){
  matrix[rowEnd][colBegin+i] = matrix[rowEnd][colBegin+i+1]; 
  
}
for(int i{0};i < ms-2*n-1; i++){
  matrix[rowEnd-i][colEnd] = matrix[rowEnd-i-1][colEnd]; 
  
}
for(int i{0};i < ms-2*n-1; i++){
  matrix[rowBegin][colEnd-i] = matrix[rowBegin][colEnd-i-1]; 
  
}

matrix[rowBegin][colBegin+1] = temp;
}
}

void rotate(vector<vector<int>>& matrix) {
  int rotateN = matrix.size()/2;
  for(int n{0}; n< rotateN;n++)
    rotateNth(matrix, n);
}