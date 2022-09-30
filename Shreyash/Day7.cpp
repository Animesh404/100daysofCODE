Knapsack with Duplicate Items

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
         if(x==0){
         memset(t,-1,sizeof(t));
         x++;
        }
    
        if(n==0||w==0)
            return 0;
        if(t[n][w]!=-1)
            return t[n][w];
        if(wt[n-1]<=w){
            return t[n][w]=max((val[n-1]+knapSack(n,w-wt[n-1],val,wt)),knapSack(n-1,w,val,wt));
        }
        else{
            return t[n][w]=knapSack(n-1,w,val,wt);
        }
    }
};

Rod Cutting

class Solution{
  public:
      int t[1002][1002];
     int x=0;
    
    int knapSack(int price[],int n,int w){
         if(x==0){
         memset(t,-1,sizeof(t));
        // w=n;
         x++;
        }
    
        if(n==0||w==0)
            return 0;
        if(t[n][w]!=-1)
            return t[n][w];
        if(n<=w){
            return t[n][w]=max((1+knapSack(price,n,w-n)),knapSack(price,n-1,w));
        }
        else{
            return t[n][w]=knapSack(price,n-1,w);
        }
    }
    int cutRod(int price[], int n) {
      return knapSack(price,n,n);
    }
};

Coin Change Maximum

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int t[n+1][amount+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(i==0)
                    t[i][j]=0;
                if(j==0)
                    t[i][j]=1;
                if(i>0 && j>0){
                    if(coins[i-1]<=j){
                        t[i][j]=min(t[i][j-coins[i-1]],t[i-1][j]);
                    }
                    else
                        t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][amount];
    }
};

Coin Change Minimum

class Solution {
public:
   
    int coinChange(vector<int>& coins, int amount) {
         int n=coins.size();
        int t[n+1][amount+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(i==0)
                    t[i][j]=INT_MAX-1;
                if(j==0)
                    t[i][j]=0;
                if(i>0 && j>0){
                    if(coins[i-1]<=j){
                        t[i][j]=min(1+t[i][j-coins[i-1]],t[i-1][j]);
                    }
                    else
                        t[i][j]=t[i-1][j];
                }
            }
        }
        if(t[n][amount]==INT_MAX-1)
            return -1;
        return t[n][amount];
    }
};