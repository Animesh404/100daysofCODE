//1
//middle of linked list

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode * slow=head;
        ListNode* fast=head;
        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            
        }
        return slow;
    }
};

//2
//reverse linked list
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nxt=head;
        while(curr!=NULL){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
};

//3
//path sum

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return false;
        if(root->val==targetSum and !root->left and !root->right)
            return true;
        return(hasPathSum(root->left, targetSum-root->val)||hasPathSum(root->right, targetSum-root->val));
    }
};

//4
//path sum 2
class Solution {
public:
    void f(TreeNode* root, int target,int sum ,vector<vector<int>> & ans,vector<int> &p){
        if(root==NULL)
            return;
        p.push_back(root->val);
        
        if(root->left==NULL and root->right==NULL)
        {
            if(root->val+sum==target)
                ans.push_back(p);
        }
        f(root->left,target,sum+root->val,ans,p);
        f(root->right,target,sum+root->val,ans,p);
         p.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> p;
        if(root==NULL)
            return ans;
        f(root,targetSum,0,ans,p);
        return ans;
    }
};


