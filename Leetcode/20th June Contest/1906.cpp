#include<bits/stdc++.h>
template <typename T>

    

class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int dp[n+1][101];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;++i){
            for(int j=1;j<=100;++j){
                dp[i+1][j]=dp[i][j];
            }
            dp[i+1][nums[i]]++;
        }
        vector<int>result;
        for(int i=0;i<queries.size();++i){
            int start=queries[i][0];
            int end=queries[i][1]+1;
            int check=-1;
            int ans=INT_MAX;
            for(int j=1;j<=100;++j){
                if(dp[end][j]!=dp[start][j]){
                    if(check==-1){
                        check=j;
                    }
                    else{
                        ans=min(ans,j-check);
                        check=j;
                    }
                }
                if(ans==1){
                    break;
                }
            }
            if(ans!=INT_MAX){
            result.push_back(ans);
            }
            else{
                result.push_back(-1);
            }
        }
        return result;
    }
};