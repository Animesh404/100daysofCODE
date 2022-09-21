//1
//path to given node

 bool f(TreeNode * A, int B, vector<int> & ans){
     if(A==NULL)
     return false;
     
     ans.push_back(A->val);
     
     if(A->val== B)
     return true;
     
     if(f(A->left,B,ans)|| f(A->right, B, ans))
     return true;
     
     ans.pop_back();
     return false;
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if(A==NULL)
    return ans;
    f(A,B,ans);
    return ans;
}

//2
//lca
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q)
            return root;
        
        TreeNode* l=lowestCommonAncestor(root->left,p,q);
        TreeNode* r=lowestCommonAncestor(root->right,p,q);
        
        if(l==NULL)
            return r;
        else if(r==NULL)
            return l;
        else
            return root;
        
    }
};

//3
//symmetric tree
class Solution {
public:
    bool f(TreeNode* l, TreeNode* r){
        if(l==NULL || r==NULL)
            return l==r;
        if(l->val != r->val)
            return false;
        return f(l->left,r->right) and f(l->right,r->left);
    }
    bool isSymmetric(TreeNode* root) {
        return f(root->left,root->right);
    }
};

//4
//right view
class Solution {
public:
    void f(TreeNode* root, int level, vector<int> & ans){
        if(root==NULL)
            return;
        if(level==ans.size())
            ans.push_back(root->val);
        f(root->right,level+1,ans);
        f(root->left,level+1,ans);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
            return ans;
        f(root,0,ans);
        return ans;
    }
};

//5
//vertical order traversal
class Solution {
public:
    void preorder(TreeNode*root, int vertical, int level,map<int, map<int, multiset<int>>> &mp){
        if(root==NULL)
            return;
        mp[vertical][level].insert(root->val);
        preorder(root->left,vertical-1,level+1,mp);
        preorder(root->right,vertical+1,level+1,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        preorder(root,0,0,mp);
        vector<vector<int>> ans;
        for(auto p:mp){
            vector<int> ds;
            for(auto q: p.second){
                for(auto r: q.second){
                    ds.push_back(r);
                }
            }
            ans.push_back(ds);
        }
        return ans;
    }
};

//6
//left view

void f(Node* root , vector<int> & ans,int level){
    if(root==NULL)
    return;
    
    if(ans.size()==level)
    ans.push_back(root->data);
    
    f(root->left,ans,level+1);
    f(root->right,ans,level+1);
    
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> ans;
    f(root,ans,0);
    return ans;
   // Your code here
}


//7
//bottom view

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        if(root==NULL)
        return ans;
        
        queue<pair<Node*,int>>q;
        
        map<int,int>mp;
        q.push({root,0});
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int line=it.second;
            Node* node=it.first;
            mp[line]=node->data;
            if(node->left)
            q.push({node->left,line-1});
            if(node->right)
            q.push({node->right,line+1});
        }
        
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};

//8 
//top view

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        queue<pair<Node*,int>> q;
        map<int,int> mp;
        q.push({root,0});
        while(!q.empty()){
            auto p=q.front();
            Node* node=p.first;
            int v=p.second;
            q.pop();
            if(mp.find(v)==mp.end())
            mp[v]=node->data;
            if(node->left)
            q.push({node->left,v-1});
            if(node->right)
            q.push({node->right,v+1});
        }
        vector<int>ans;
        for(auto p:mp){
            ans.push_back(p.second);
        }
        return ans;
        //Your code here
    }

};

