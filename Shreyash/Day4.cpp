#Permutation_Sequence

class Solution {
public:

  string getPermutation(int n, int k) {
        int fact = 1;
      vector < int > v;
      for (int i = 1; i < n; i++) {
        fact = fact * i;
        v.push_back(i);
      }
      v.push_back(n);
      k=k-1;
      string ans="";
      while(true){
          ans+=to_string(v[k/fact]);
          v.erase(v.begin()+k/fact);
          if(v.size()==0)
              break;
          k=k%fact;
          fact=fact/v.size();
      }
      return ans;
  }
};

#Palindrome_Partition

class Solution {
public:
    bool palin(string s,int start,int end){
        int i=start,j=end;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
       return true;
    }
    void check(string s,vector<vector<string>> &ans,vector<string> ans1,int index){
        if(index==s.size()){
            ans.push_back(ans1);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(palin(s,index,i)){
                ans1.push_back(s.substr(index,i-index+1));
                check(s,ans,ans1,i+1);
                ans1.pop_back();
            }
        }
        
        
    }
    vector<vector<string>> partition(string s) {
       vector<string> ans1;
        vector<vector<string>> ans;
        check(s,ans,ans1,0);
        return ans;
        
    }
};

#Cmbination_Sum_2

class Solution {
public:
      void solve(int ind,int target,vector<int> &arr,vector<int> &sol,vector<vector<int>> &ans){
          if(target == 0){
              ans.push_back(sol);
              return;
            }
            for(int k=ind;k<arr.size();k++){
                if(k>ind && arr[k]==arr[k-1])
                    continue;
                if(arr[k]>target)
                    break;
                sol.push_back(arr[k]);
                solve(k+1,target-arr[k],arr,sol,ans);
                sol.pop_back();
            }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> sol;
        vector<vector<int>> ans;
    
        //vector<vector<int>> st;
       
        solve(0,target,candidates,sol,ans);
        // for(auto it:ans){
        //     st.push_back(it);
        // }
        return ans;;
    
    }
};