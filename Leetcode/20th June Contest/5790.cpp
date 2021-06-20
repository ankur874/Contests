#include<bits/stdc++.h>
template <typename T>
class Solution {
    
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
          for(int i=0;i<queries.size();i++){
              int l=queries[i][0];
              int r=queries[i][1];
              int mini=INT_MAX;
              for(int j=l;j<r;j++){
                  if(abs(nums[j]-nums[j+1])!=0)
                  mini=min(mini,abs(nums[j]-nums[j+1]));
              }
              if(mini==0)
                  ans.push_back(-1);
              else
              ans.push_back(mini);
          }    
          return ans;

                 
    }
};