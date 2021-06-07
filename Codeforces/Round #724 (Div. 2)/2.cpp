#include<iostream>
#include<vector>
#include<unordered_set>
typedef long l;
using namespace std;
bool isNice(vector<l>&a){
    unordered_set<l>s;
    for(int i=0;i<a.size();i++){
        s.insert(a[i]);
    }
    for(int i=0;i<a.size();i++){
        for(int j=i+1;j<a.size();j++){
            if(s.find(abs(a[i]-a[j]))!=s.end()){
                 continue;
            }else{
                s.insert(abs(a[i]-a[j]));
                a.push_back(abs(a[i]-a[j]));
                if(a.size()>300){
                    return false;
                }
            }
        }
    }
    if(a.size()<=300){
        return true;
    }else{
        return false;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<l>a;
        for(int i=0;i<n;i++){
            l el;
            cin>>el;
            a.push_back(el);
        }
        bool is_nice=isNice(a);
        if(is_nice==true){
            cout<<"YeS"<<endl;
            cout<<a.size()<<endl;
            for(int i=0;i<a.size();i++){
                cout<<a[i]<<" ";
            }
        }
        else{
            cout<<"nO";
        }
        cout<<endl;
    }
    return 0;
}