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