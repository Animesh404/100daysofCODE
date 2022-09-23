#Letter_Case_Permutations

class Solution {
public:
    void compute(string s,string n,set<string> &ans){
        if(s.length()==0){
            ans.insert(n);
            return;
        }
        string s1=n;
        string s2=n;
        if(s[0]>=97&&s[0]<=122){
            s1.push_back(s[0]);
            s2.push_back(s[0]-32);
        }
        else  if(s[0]>=65&&s[0]<=90){
            s1.push_back(s[0]);
            s2.push_back(s[0]+32);
        }
        
        else{
            s1.push_back(s[0]);
            s2.push_back(s[0]);
        }
        s.erase(s.begin()+0);
        compute(s,s1,ans);
        compute(s,s2,ans);
        return;
    }
    vector<string> letterCasePermutation(string s) {
        set<string> st;
        compute(s,"",st);
        vector<string> sol;
        for(auto it:st){
            sol.push_back(it);
        }
        return sol;
    }
};

#Permutation_With_Spaces

class Solution {
public:
    void compute(string s,string n,set<string> &ans){
        if(s.length()==0){
            ans.insert(n);
            return;
        }
        string s1=n;
        string s2=n;
        if(s[0]>=97&&s[0]<=122){
            s1.push_back(s[0]);
            s2.push_back(s[0]-32);
        }
        else  if(s[0]>=65&&s[0]<=90){
            s1.push_back(s[0]);
            s2.push_back(s[0]+32);
        }
        
        else{
            s1.push_back(s[0]);
            s2.push_back(s[0]);
        }
        s.erase(s.begin()+0);
        compute(s,s1,ans);
        compute(s,s2,ans);
        return;
    }
    vector<string> letterCasePermutation(string s) {
        set<string> st;
        compute(s,"",st);
        vector<string> sol;
        for(auto it:st){
            sol.push_back(it);
        }
        return sol;
    }
};

#Combination_Sum

class Solution {
public:
    void solve(vector<int> candidates,vector<int> sol,int target,int ind,vector<vector<int>> &ans){
        if(ind == candidates.size()){
            if(target == 0){
                 ans.push_back(sol);
            }
            return;
        }
        if(candidates[ind]<=target){
        sol.push_back(candidates[ind]);
        solve(candidates,sol,target-candidates[ind],ind,ans);
        sol.pop_back();
        }
        
        solve(candidates,sol,target,ind+1,ans);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sol;
        vector<vector<int>> ans;
        solve(candidates,sol,target,0,ans);
        return ans;
    }
};