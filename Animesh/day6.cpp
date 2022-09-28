//Matrix median using Binary Search
int cSmallEq(vector<int> &ro,int mid){
    int lo=0,hi=ro.size()-1;
    while(lo<=hi){
        int md=lo+(hi-lo)/2;
        if(ro[md]<=mid){
            lo=md+1;
        }
        else   hi=md-1;
    }
    return lo;
}
int Solution::findMedian(vector<vector<int> > &A) {
    int lo=1;
    int hi=1e9;
    int n=A.size();
    int m=A[0].size();
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=cSmallEq(A[i],mid);
        }
        if(cnt<=(n*m)/2)    lo=mid+1;
        else hi=mid-1;
    }
    return lo;
}
//single element in sorted array
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo=0;
        int hi=nums.size()-2;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==nums[mid^1])  lo=mid+1;//mid^1 will return 1 element before if odd or 1 elem. after mid if even.
            else hi=mid-1;
        }
        return nums[lo];
    }
};
