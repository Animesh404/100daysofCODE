#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n+1);
    unordered_map<int,int> mp;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }
    vector<int> queries(q);
    for(int i=0;i<q;i++){
        cin>>queries[i];
    }
    for(int i=0;i<q;i++){
        auto it = mp.find(queries[i]);
        cout<<it->second<<endl;
    }
}