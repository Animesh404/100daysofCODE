Shortest Common Supersequence

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        int t[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0)
                    t[i][j]=0;
                if(i>0 && j>0){
                    if(str1[i-1]==str2[j-1]){
                        t[i][j]=1+t[i-1][j-1];
                    }
                    else{
                        t[i][j]=max(t[i-1][j],t[i][j-1]);
                    }
                }
            }
        }
        string s;
        int i=n,j=m;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1])
            {
                s.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if(t[i][j-1]>t[i-1][j]){
                //cout<<str2[j-1]<<endl;
                s.push_back(str2[j-1]);
                j--;
            }
            else{
                 // cout<<str1[i-1]<<endl;
                 s.push_back(str1[i-1]);
                i--;
            }
               
        }
        while(i>0){
            s.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            s.push_back(str2[j-1]);
            j--;
        }
        reverse(s.begin(),s.end());
        
        return s;
    }
};

Minimum Insertion Steps to Make a String Palindrome

class Solution {
public:
     int lcs(int n, int m, string s1, string s2)
    {
        // your code here
         int t[n+1][m+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 || j==0)
                    t[i][j]=0;
                if(i>0 && j>0){
                    if(s1[i-1]==s2[j-1])
                        t[i][j]=1+t[i-1][j-1];
                    else
                          t[i][j]=max(t[i][j-1],t[i-1][j]);
                }
            }
        }
        return t[n][m];
    }
    int minInsertions(string str) {
         string y;
        for(int i=str.length()-1;i>=0;i--){
            y.push_back(str[i]);
        }
        int x=lcs(str.length(),str.length(),str,y);
        return ((str.length()-x));
    }
};