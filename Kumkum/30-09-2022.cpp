#include<bits/stdc++.h>
using namespace std;

//1
// search in a rotated sorted array
class Solution {
public:
    int getPivot(vector<int>& nums, int n){
        int s = 0;
        int e = n-1;
        int m = s + (e-s)/2;
        while(s < e){
            if(nums[m] >= nums[0]){
                s = m+1;
            }
            else{
                e = m;
            }
            m = s + (e-s)/2;
        }
        return s;
    }
    int binarysearch(vector<int>& nums, int s, int e, int target){
        int m = s + (e-s)/2;
        while(s <= e){
            if(nums[m]== target){
                return m;
            }
            else if(nums[m]< target){
                s = m+1;
            }
            else{
                e = m-1;
            }
            m = s + (e-s)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int i=getPivot(nums,n);
        cout<<i<<endl;
        if(target >= nums[i] && target <= nums[n-1]){
            return binarysearch(nums, i, n-1, target);
        }
        else{
            return binarysearch(nums, 0, i-1, target);
        }
    } 
    
};

//2
//first and last position of element in a sorted array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n=nums.size();
        int first=-1;
        int l=0,r=n-1;
        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]==target){
                first=m;
                r=m-1;
            }
            else if(nums[m]<target)
                l=m+1;
            else{
                r=m-1;
            }
        }
        int last=-1;
        l=0,r=n-1;
        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]<=target){
                if(nums[m]==target)
                    last=m;
                l=m+1;
            }
                else{
                    r=m-1;
                }
        }
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};
