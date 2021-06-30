template <typename t>
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
         int n=grid.size();
         int m=grid[0].size();
         k=k%(n*m);
         while(k--){
             int row=0;
             int col=0;
             while(row<=n/2&&col<=m/2){
                 int i=row,j=col;
                 int temp=grid[i][j];
                 int temp2;
                 while(i<n-1){
                     temp2=grid[i+1][j];
                     grid[i+1][j]=temp;
                     temp=temp2;
                     i++;
                 }
                 int temp3;
                 while(j<m-1){
                     temp3=grid[i][j+1];
                     grid[i][j+1]=temp2;
                     temp2=temp3;
                     j++;
                 }
                 int temp4;
                 while(i>row){
                     temp4=grid[i-1][j];
                     grid[i-1][j]=temp3;
                     temp3=temp4;
                     i--;
                 }
                 int temp5;
                 while(j>col){
                     temp5=grid[i][j-1];
                     grid[i][j-1]=temp4;
                     temp4=temp5;
                     j--;
                 }
                 row++;
                 col++;
                 n--;
                 m--;
             }
         }
         return grid;
    }
};