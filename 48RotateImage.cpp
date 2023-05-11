 class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int g=0;g<matrix.size();g++){
            for(int i=0,j=g;j<matrix.size();i++,j++){
                int t=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=t;
            }
        }
        for(int i=0;i<matrix.size();i++){
            int l=0,h=matrix.size()-1;
            while(l<h){
                int t=matrix[i][l];
                matrix[i][l]=matrix[i][h];
                matrix[i][h]=t;
                l++;
                h--;
            }
        }
    }
};