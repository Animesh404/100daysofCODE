//1
//find the winner in circular friends circle

class Solution {
public:
    void f(int ind, int &ans, int k, vector<int> &a ){
    if(a.size()==1)
    {
        ans=a[0];
        return;
    }
    ind=(ind+k)%a.size();
    a.erase(a.begin()+ind);
    f(ind,ans, k,a);
}
    int findTheWinner(int n, int k) {
        vector<int> a;
        for(int i=1;i<=n;i++)
            a.push_back(i);
        k--;
        int ind=0;
        int ans=-1;
        f(ind,ans,k,a);
        return ans;
    }
};

//2
//concatenation of consecutive binary numbers

class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans=0, mod=1e9+7, len=0;
        for(int i=1;i<=n;i++){
            if((i&(i-1))==0)
                len++;
            ans= ((ans<<len)+i)%mod;
        }
        return ans;
        
    }
};

//3
//excel column number
int Solution::titleToNumber(string A) {
    int result=0;
    for(auto c: A){
        int d= c-'A'+1;
        result=result*26+d;
    }
    return result;
}


//4
//excel column title
string Solution::convertToTitle(int A) {
    string ans="";
    while(A){
        A--;
        char x= (A%26 )+'A';
        ans=x+ans;
        A/=26;
    }
    return ans;
}

//5
//cells in a range
class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        char c1= s[0];
        char c2= s[3];
        while(c1<=c2){
                    int x1= s[1]-'0';
                    int x2= s[4]-'0';
            while(x1<=x2){
                ans.push_back(c1+to_string(x1));
                x1++;
            }
            c1++;
        }
        return ans;
    }
};

//6
//max width of a tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
                int width=0;

        if(root==NULL)
            return width;
        
        queue<pair<TreeNode*,long long>> q;
        
        q.push({root,0});
        
        while(!q.empty()){
            
            // auto it=q.front();
            
            int sz= q.size();
            
            long long minimum=q.front().second;
            
            int first, last;
            
            for(int i=0;i<sz;i++){
                
                long long  current= q.front().second-minimum;
                
                TreeNode* node= q.front().first;
                
                q.pop();
                
                if(i==0)
                    first=current;
                
                if(i==sz-1)
                    last=current;
                
                if(node->left)
                    q.push({node->left,((2*current)+1)});
                
                if(node->right)
                    q.push({node->right,((2*current)+2)});
            }
            width=max(width,(last-first+1));
        }
        return width;
        
    }
};

//7
//convert to mirror
class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
         if(node==NULL ) return ;

       mirror(node->left);

       mirror(node->right);

       swap(node->left, node->right);
        // code here
    }
};

