#Perfect_Sum_Problem

class Solution {
public:
    bool subset(vector<int>arr,int n ,int sum){
        bool t[n+1][sum+1];
        for(int i=0;i<=n;i++){
            t[i][0]=true;
        }
         for(int i=1;i<=sum;i++){
            t[0][i]=false;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                 if(arr[i-1]<=j){
            t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
        }
        else{
            t[i][j]=t[i-1][j];
        }
            }
        }
       
        return t[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0)
            return false;
        else{
            return subset(nums,nums.size(),sum/2);
        }
       
    }
};

#Minimum_Sum_Partition

class Solution{

  public:
    int subset(int arr[],int sum,int n){
        bool t[n+1][sum+1];
        vector<int> sol;
        int ans=INT_MAX;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0){
                    t[i][j]=false;
                    
                }
                if(j==0){
                    t[i][j]=true;
                }
                if(i>0 && j>=0){
                    if(arr[i-1]<=j){
                        t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
                    }
                    else{
                        t[i][j]=t[i-1][j];
                    }
                }
            }
        }
         for(int i=0;i<=sum;i++){
	        if(i<=sum/2 && t[n][i]==true)
	            sol.push_back(i);
	    }
	    for(int i=0;i<sol.size();i++){
	        ans=min(ans,sum-2*sol[i]);
	    }
	    return ans;
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    vector<int> sol;
	    sort(arr,arr+n);
	    int ans=INT_MAX;
	    int s=0;
	    for(int i=0;i<n;i++){
	        s+=arr[i];
	    }
	    int x=subset(arr,s,n);
	    return x;
	   
	    return ans;
	} 
};

#Target_Sum

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
       int sum=accumulate(nums.begin(),nums.end(),0);
        if(abs(target) > sum)
            return 0;
            
        if((abs(target) + sum) % 2 != 0)
            return 0;
        (target)=(abs(target)+sum)/2;
        
         int t[nums.size()+1][abs(target)+1];
        for(int i=0;i<=nums.size();i++){
            for(int j=0;j<=abs(target);j++){
                if(i==0)
                    t[i][j]=0;
                if(j==0)
                    t[i][j]=1;
                if(i>0 && j>=0){
                    if(nums[i-1]<=j){
                        t[i][j]=t[i-1][j-nums[i-1]]+(t[i-1][j]);
                    }
                    else{
                        t[i][j]=(t[i-1][j]);
                    }
                }
            }
        }
        
        return t[nums.size()][abs(target)];
    }
};
