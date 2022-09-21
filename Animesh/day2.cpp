//palindrome partitioning
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> st;
        func(s,0,st,res);
        return res;
    }
    void func(string &s,int ind,vector<string> &st,vector<vector<string>> &res){
        if(ind==s.size()){
            res.push_back(st);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPal(ind,i,s)){
                st.push_back(s.substr(ind,i-ind+1));
                func(s,i+1,st,res);
                st.pop_back();
            }
        }
    }
    bool isPal(int start,int end,string stri){
            while(start<end){
                if(stri[start++]!=stri[end--])  return false;
            }
            return true;
        }
};
//permutation sequence
class Solution {
public:
    string getPermutation(int n, int k) {
        int fct=1;
        vector<int> nums;
        for(auto i=1;i<n;i++){
            fct = fct*i;
            nums.push_back(i);
        }
        nums.push_back(n);
        string res="";
        k=k-1;
        while(true){
            res=res+to_string(nums[k/fct]);
            nums.erase(nums.begin()+k/fct);
            if(nums.size()==0)  break;
            k=k%fct;
            fct=fct/nums.size();
        }
        return res;
    }
};
