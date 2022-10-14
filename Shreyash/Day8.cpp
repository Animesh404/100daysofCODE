Maximum Length of Repeated Subarray

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int t[n+1][m+1];
        int ans=0;
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 || j==0)
                    t[i][j]=0;
                if(i>0 && j>0){
                    if(nums1[i-1]==nums2[j-1])
                        t[i][j]=1+t[i-1][j-1];
                    else
                        t[i][j]=0;
                    ans=max(ans,t[i][j]);
                }
            }
        }
        return ans;
        
        
    }
};

LCS

class Solution {
public:
    // int t[1001][1001];
    // int z=0;
    // int longestCommonSub (string x, string y, int n, int m)
    // {   
    //     if(z==0){
    //         memset(t,-1,sizeof(t));
    //         z++;
    //     }
    //     if(n==0 || m==0)
    //         return 0;
    //     if(t[n][m]!=-1)
    //         return t[n][m];
    //     if(x[n-1]==y[m-1])
    //         return t[n][m]=1+longestCommonSub(x,y,n-1,m-1);
    //     else
    //         return t[n][m]=max(longestCommonSub(x,y,n-1,m),longestCommonSub(x,y,n,m-1));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        //return longestCommonSub(text1,text2,text1.length(),text2.length());
        int n=text1.length();
        int m=text2.length();
        int t[n+1][m+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 || j==0)
                    t[i][j]=0;
                if(i>0 && j>0){
                    if(text1[i-1]==text2[j-1])
                        t[i][j]=1+t[i-1][j-1];
                    else
                          t[i][j]=max(t[i][j-1],t[i-1][j]);
                }
            }
        }
        return t[n][m];
    }
};