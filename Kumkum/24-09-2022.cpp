//1
///multiply strings

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int n=num1.size();
        int m=num2.size();
        vector<int> arr(n+m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int mul = (num1[i]-'0')*(num2[j]-'0');
                int sum = arr[i+j+1]+mul;
                arr[i+j]+= sum/10;
                arr[i+j+1]=sum%10;
				
            }
        }
        string res;
		int i = 0;
		while (i < arr.size() && arr[i] == 0) i++;
		while (i < arr.size()) res.push_back(arr[i++] + '0');
		return res;
        
    }
};

//2
//children sum property

void changeTree(BinaryTreeNode < int > * root) {
    if(root==NULL)
        return;
    int sum=0;
    if(root->left)
        sum+=(root->left->data);
    if(root->right)
        sum+=(root->right->data);
    
    if(sum>=root->data)
        root->data=sum;
    else{
        if(root->left)
            root->left->data=root->data;
        if(root->right)
            root->right->data=root->data;
    }
    
    changeTree(root->left);
    changeTree(root->right);
    
    int total=0;
    if (root -> left) total += root -> left -> data;
  if (root -> right) total += root -> right -> data;
  if (root -> left || root -> right) root -> data = total;
    // Write your code here.
}  

//3
//nodes at k distance

class Solution {
public:
    void markparent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
                parent[curr->left]=curr;
            }
            if(curr->right){
                q.push(curr->right);
                parent[curr->right]=curr;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        markparent(root,parent);
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int level=0;
        while(!q.empty()){
            int size=q.size();
            if(level++ == k)
                break;
            for(int i=0;i<size;i++){
                TreeNode* current =q.front();
                q.pop();
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left]=true;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right]=true;
                }
                if(parent[current] && !visited[parent[current]]){
                    q.push(parent[current]);
                    visited[parent[current]]=true;
                }
            }
         }
         vector<int> ans;
         while(!q.empty()) {
            TreeNode* current = q.front(); 
            q.pop();
            ans.push_back(current->val);
        }
        return ans;
}
    
};

//4
//interview bit-fizz buzz

vector<string> Solution::fizzBuzz(int n) {
    vector<string> ans(n);
    for(int i=0;i<n;i++){
        if((i+1)%3==0 && (i+1)%5!=0)
        {
            ans[i]="Fizz";
        }
        else if((i+1)%3==0 && (i+1)%5==0)
        {
            ans[i]="FizzBuzz";
        }
        else if((i+1)%3!=0 && (i+1)%5==0)
        {
            ans[i]="Buzz";
        }
        else{
            ans[i]=to_string(i+1);
        }
    }
    return ans;
}


//5
//total moves for bishop
int Solution::solve(int A, int B) {
    int top_l=min(A,B)-1;
    int top_r=min(A,9-B)-1;
    int bot_l=8-max(A,9-B);
    int bot_r=8-max(A,B);
    return top_l+top_r+bot_l+bot_r;
}


