#include<bits/stdc++.h>
using namespace std;
//1
//power of two
bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        return ((n&(n-1))==0);
    }

//2
//atlassian- winner of an election

class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        unordered_map< string , int > mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int curr=0;
        string winner;
        vector<string> ans;
        
        for(auto x: mp){
            if(x.second>curr)
            {
                curr=x.second;
                winner=x.first;
            }
            else if(x.second==curr and winner>x.first)
            {
                winner=x.first;
            }
        }
        
        string x=to_string(curr);
        ans.push_back(winner);
        ans.push_back(x);
        return ans;
        
        
    }
};

//3
//atlassian moore voting algo

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int n)
    {
        int cnt=0,ele=0;
        for(int i=0;i<n;i++){
            if(cnt==0){
            ele=i;
            // cnt=1;
            }
            if(a[ele]==a[i])
            cnt+=1;
            else
            cnt-=1;
        }
        cnt=0;
        for(int i=0;i<n;i++){
            if(a[ele]==a[i])
            cnt++;
        }
        if(cnt<=n/2)
        return -1;
        else
        return a[ele];
        // your code here
        
    }
};