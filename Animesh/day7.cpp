#include<bits/stdc++.h>
using namespace std;

//First occurence of 1
int bSearch(int lo,int hi,int a[]){
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(a[mid]==1) hi=mid-1;
        else lo=mid+1;
    }
    return lo;
}

int main(){
    int a[9]={0,0,0,0,0,1,1,1,1};
    int l=0;
    int h=8;
    cout<<"\n"<<bSearch(l,h,a);
    return 0; 
}
// WoodCutter SPOJ
int l=0,r=*max_element(a,a+n),ans=0; 

    while(l<=r){
        int mid = l+(r-l)/2;
        int res=0;
        for(int i=0;i<n;i++){
            if(a[i]>mid){
                res+=a[i]-mid;
            }
        }
        if(res>=m){ 
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;

