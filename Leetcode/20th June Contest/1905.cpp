template <typename t>
class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int &flag,int n,int m,int i,int j){
        if(i<0||j<0||i>=n||j>=m||grid2[i][j]==0)return ;
        if(grid1[i][j]==0)flag=0;
        grid2[i][j]=0;
        dfs(grid1,grid2,flag,n,m,i,j-1);
        dfs(grid1,grid2,flag,n,m,i,j+1);
        dfs(grid1,grid2,flag,n,m,i-1,j);
        dfs(grid1,grid2,flag,n,m,i+1,j);



    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int n=grid1.size();
        int m=grid1[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(grid2[i][j]==1){
                  int flag=1;
              dfs(grid1,grid2,flag,n,m,i,j);
              ans+=flag;
              }
            }
        }
       return ans;
    }
};