//Search in sorted rotated array
class Solution {
public:
    int bs(vector<int> a,int l,int h,int target){
        int m = l + (h-l)/2;
        while(l<=h){
            if(a[m]==target) return m;
            else if(a[m]>target) h=m-1;
            else l=m+1;
            m = l + (h-l)/2;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n=nums.size()-1;
        int lo=0;
        int hi=n;
        int pi=0;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>=nums[0])  lo = mid+1;
            else if(nums[mid]<nums[0]) hi=mid;
        }
        pi=lo;
        if(target>=nums[pi] and target<=nums[n]){
            return bs(nums,pi,n,target);
        }
        else
           return bs(nums,0,pi-1,target);
           
           }
    };