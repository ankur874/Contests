#include<vector>
template <typename T>
class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
         sort(packages.begin(),packages.end());
         for(int i=0;i<boxes.size();i++){
             sort(boxes[i].begin(),boxes[i].end());
         }
         int minWasted=INT_MAX;
         bool isPresent=false;
         for(int i=0;i<boxes.size();i++){
             int minWastedInI=0;
             int p=0;
             int b=0;
             if(packages[packages.size()-1]<=boxes[i][boxes[i].size()-1]){
             isPresent=true;
             while(p<packages.size()&&b<boxes[i].size()){
                 if(boxes[i][b]>=packages[p]){
                     minWastedInI+=(boxes[i][b]-packages[p]);
                     p++;
                 }else{
                     b++;
                 }
             }
             minWasted=min(minWasted,minWastedInI);
             }
         }
      if(isPresent==true){
          return minWasted;
      }
      return -1;
         
    }
};