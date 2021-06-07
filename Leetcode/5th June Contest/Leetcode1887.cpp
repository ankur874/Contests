#include<vector>
template <typename T>
class Solution {
public:
    int reductionOperationsHelper(int *arr,int n,int* dp){
        if(n<=1){
            return 0;
        }
        if(dp[n]>-1){
            return dp[n];
        }
        sort(arr,arr+n);
        int o1=reductionOperationsHelper(arr+1,n-1,dp);
        if(arr[0]==arr[1]){
            dp[n]= o1;
        }else{
        dp[n]= o1+n-1;
        }
        int ans=dp[n];
        delete []dp;
        return ans;
    }
    int reductionOperationsIter(int *arr,int n){
        sort(arr,arr+n);
          int ans=0;
          for(int i=n-1;i>0;i--){
              if(arr[i]!=arr[i-1]){
                  ans+=(n-i);
              }
          }
          return ans;
    }
    int reductionOperations(vector<int>& nums) {
        int n=nums.size();
        int *arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=nums[i];
        }
        int *dp=new int[n+1];
        for(int i=0;i<n;i++){
            dp[i]=-1;
        }
        //return reductionOperationsHelper(arr,n,dp);
        return reductionOperationsIter(arr,n);
        
    }
};