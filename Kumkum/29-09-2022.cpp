#include<bits/stdc++.h>
using namespace std;
//1
//find k closest
 vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        
        int n=arr.size();
        
        int left=0,right=n-1;
        
        while(right-left>=k){

            
            if(abs(x-arr[left])>abs(x-arr[right])){
                left++;
            }
            
            else{
                right--;
            }
            
        }
        for(int i=left;i<=right;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }

//2
//find first positive
//first approach
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
            if(nums[i]<=0 )
                nums[i]=n+1;
        for(int i=0;i<n;i++){
            if(abs(nums[i]) <= n and nums[abs(nums[i])-1]>0)
                nums[abs(nums[i])-1]*=-1;
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0)
                return i+1;
        }
        return n+1;
    }
};
//second approach

//3
//code ism
long marcsCakewalk(vector<int> calorie) {
    long ans=0;
    int n=calorie.size();
    sort(calorie.begin(),calorie.end(),greater<>());
    for(int i=0;i<n;i++)
    {
        ans+=((pow(2,i))*calorie[i]);
    }
    return ans;
}

//4
//good pairs
int numIdenticalPairs(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        int goodPairs = 0;
        
        for(int i=0; i<nums.size(); i++)
            mp[nums[i]] ++;
        
        for(auto x : mp)
            goodPairs += x.second * (x.second - 1) / 2;
        
        return goodPairs;
    }

