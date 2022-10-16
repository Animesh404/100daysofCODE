#include<bits/stdc++.h>
using namespace std;
int main(){
    int A[2]={3, 2};
    int B[2]={1,4};
    int C=2;
    priority_queue<int> minH;
    vector<int> res;
    
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            int sum=A[i]+B[i];
            minH.push(sum);
            if(minH.size()>C)   minH.pop();
        }
    }
    while(!minH.empty())    res.push_back(minH.top());
     for(auto x:res)    cout<<x<<" ";
    return 0;
}