Subset_Sums

 void sum(int d,vector<int> &sol,vector<int> arr,int N){
        if(arr.empty()){
            sol.push_back(d);
            return;
        }
        int d1=d;
        int d2=d;
        d2+=arr[0];
        arr.erase(arr.begin()+0);
        sum(d1,sol,arr,N);
        sum(d2,sol,arr,N);
        return;
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> sol;
        sum(0,sol,arr,N);
        return sol;
    }

#Partition_Equal_Subset_Sum

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

