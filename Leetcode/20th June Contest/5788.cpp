#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestOddNumber(string num) {
        if(num==""){
            return "";
        }
        string ans="";
         for(int i=num.length()-1;i>=0;i--){
               if((num[i]-'0')&(1<<0)){
                   ans=num.substr(0,i+1);
                   break;
               }
         }
         return ans;
    }
};