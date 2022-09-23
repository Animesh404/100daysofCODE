// //swap nodes in pairs
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        return func(head);
    }
    ListNode* func(ListNode* fp){
        if(fp==NULL or fp->next==NULL)    return fp;
        ListNode* temp=fp->next;
        fp->next=temp->next;
        temp->next=fp;
        fp=temp;
        fp->next->next=func(fp->next->next);
        return fp;
    }
};
//Find the winner of the Circular Game
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>res;
        k--;
        for(int i=1;i<=n;i++) res.push_back(i);
        func(0,k,res);
        return res[0]; 
    }
    void func(int ind,int k,vector<int>&res){
        if(res.size()==1)   return;
        ind = (ind%res.size()+k%res.size())%res.size();
        res.erase(res.begin()+ind);
        func(ind,k,res);
    }
};
//permutations
//APPROACH 1
class Solution {
public:
    void func(vector<int>& nums,vector<int> &ds,vector<vector<int>>& res,vector<int> freq){
        if(ds.size()==nums.size()){
            res.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(freq[i]==0){
                ds.push_back(nums[i]);
                freq[i]++;
                func(nums,ds,res,freq);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        int n=nums.size();
        vector<int> mp(n,0);
        func(nums,ds,res,mp);
        return res;
    }
};
//permutations
//APPROACH 2