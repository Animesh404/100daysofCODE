Longest Palindromic Subsequence

class Solution {
public:
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
    int longestPalindromeSubseq(string A) {
         string B;
        for(int i=A.length()-1;i>=0;i--){
            B.push_back(A[i]);
        }
        return longestCommonSubsequence(A,B);
    }
};

Minimum number of deletions and insertions.
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{   int ans;
	     int n=str1.length();
        int m=str2.length();
        int t[n+1][m+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 || j==0)
                    t[i][j]=0;
                if(i>0 && j>0){
                    if(str1[i-1]==str2[j-1])
                        t[i][j]=1+t[i-1][j-1];
                    else
                          t[i][j]=max(t[i][j-1],t[i-1][j]);
                }
            }
        }
        ans= t[n][m];
	   //cout<<ans<<endl;
	    if(m<n)
	        return (abs(ans-m)+abs(n-ans));
         return (abs(ans-n)+abs(m-ans));	         
	    
	} 
};