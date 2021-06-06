class Solution {
public:
void rotateMatrix(vector<vector<int>>& mat,int n){
    vector<vector<int>>& temp;
    temp=mat;
    for(int i=0;i<n;i++){
        int c=i;
        int r=n-1;
        for(int j=0;j<n;j++){
             mat[i][j]=temp[r--][c];
        }
    }
}
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=target.size();
        if(mat==target){
            return true;
        }
        for(int i=0;i<3;i++){
             rotateMatrix(mat,n);
             if(mat==target){
                 return true;
             }
        }
        return false;
    }
};