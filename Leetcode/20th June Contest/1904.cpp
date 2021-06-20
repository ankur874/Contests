#include<bits/stdc++.h>
#include<string>
using namespace  std;

class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int h1=(((int)startTime[0]-'0')*10+(int)(startTime[1]-'0'));
        int h2=(((int)finishTime[0]-'0')*10+(int)(finishTime[1]-'0'));
        int m1=(((int)startTime[3]-'0')*10+(int)(startTime[4]-'0'));
        int m2=(((int)finishTime[3]-'0')*10+(int)(finishTime[4])-'0');
        if(h1>h2||h1==h2&&m1>m2){
            h2+=24;
        }
        int tt1=h1*60+m1;
        int tt2=h2*60+m2;
        if(tt1%15!=0){
            tt1=tt1+(15-(tt1%15));
        }
        int count=0;
        for(int i=tt1;i<=tt2;i+=15){
            if(i+15<=tt2)count++;
        }
        return count;
    }
};