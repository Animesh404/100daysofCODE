#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    static bool cmp(pair<int,int> a,pair<int,int> b)
        {
            return a.second<b.second;
        }
    int findPlatform(int arr[], int dep[], int n)
    {   if(n==0)
            return 0;
        sort(arr,arr+n);
        sort(dep,dep+n);
        int sol=1;
        int c=1;
        int i=1,j=0;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                c++;
                i++;
                
            }
            else if (arr[i]>dep[j]){
                c--;
                j++;
                //cout<<c;
            }
            sol=max(sol,c);
            
           
        }
        return sol;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   // cout<<"hello";
   return 0;
}
