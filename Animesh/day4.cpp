// //swap nodes in pairs
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         return func(head);
//     }
//     ListNode* func(ListNode* fp){
//         if(fp==NULL or fp->next==NULL)    return fp;
//         ListNode* temp=fp->next;
//         fp->next=temp->next;
//         temp->next=fp;
//         fp=temp;
//         fp->next->next=func(fp->next->next);
//         return fp;
//     }
// };

#include <bits/stdc++.h>
using namespace std;
    void func(int ind,vector<int>&res){
        if(res.size()==1)   return;
        for(auto it=res.begin();it!=res.end();it++){
            if(*it==(ind+1)) res.erase(it);
        }
        if(res.size()==2)   func(ind+1,res);
        func(ind+2,res);
    }
    int findTheWinner(int n, int k) {
        vector<int>res;
        for(int i=1;i<=n;i++) res.push_back(i);
        func(0,res);
        return res[0]; 
    }

    int main(){
        int x,y;
        cin>>x>>y;
        return findTheWinner(x,y);
    }