#include<bits/stdc++.h>
using namespace std;

//1
//equalize the array
int equalizeArray(vector<int> arr) {
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        int freq=0;
        int num=arr[i];
        while(i<n and arr[i]==num){
            freq++;
            i++;
        }
        i--;
        ans=min(ans,n-freq);
    }
    return ans;

}

//2
//choose me
//time complexity: o(nlogn)
int main(){
    int n;
    cin>>n;
    vector<pair<long long,long long>> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    int x=0,y=0;
    for(int i=0;i<n;i++)
    x+=arr[i].first;

    for(int i=0;i<n;i++){
        int temp=arr[i].first;
        arr[i].first=2*arr[i].first+arr[i].second;//difference is 2a+b
        arr[i].second=temp;//(2a+b,a)
    }

    sort(arr.begin(),arr.end(),greater<>());
    int i=0;
    int ans=0;
    while(x>=y){//o(n)
        ans++;
        y+=arr[i].first-arr[i].second;
        x-=arr[i].second;
        i++;
    }
    cout<<ans<<endl;


}