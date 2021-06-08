#include<vector>
template <typename T>

class Solution {
typedef long long ll;
ll mod=1e9+7;
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
         sort(packages.begin(),packages.end());
         for(int i=0;i<boxes.size();i++){
             sort(boxes[i].begin(),boxes[i].end());
         }
         ll sum=0;
         for(int i=0;i<packages.size();i++){
           sum+=packages[i];
         }
         ll minWasted=LONG_MAX;
         bool isPresent=false;
         for(int i=0;i<boxes.size();i++){
             if(packages[packages.size()-1]<=boxes[i][boxes[i].size()-1]){
             ll minWastedInI=0;
             int b=0;
             isPresent=true;
             int currI;
             int prev=0;
             while(b<boxes[i].size()){
                 currI=upper_bound(packages.begin()+prev,packages.end(),boxes[i][b])-packages.begin();
                 minWastedInI=minWastedInI+boxes[i][b]*(currI-prev);
                 prev=currI;
                 b++;
             }
             minWasted=min(minWasted,minWastedInI)%mod;
             }
         }
      if(isPresent==true){
          return (minWasted-sum)%mod;
      }
      return -1;
         
    }
};