
//Kth element in 2 sorted arrays

class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
     if(n>m)    return kthElement(arr2,arr1,m,n,k);
     
     int lo=max(0,k-m),hi=min(k,n);
     
     while(lo<=hi){
         int cut1=lo+(hi-lo)/2;
         int cut2=k-cut1;
         int l1=cut1==0?INT_MIN:arr1[cut1-1];
         int l2=cut2==0?INT_MIN:arr2[cut2-1];
         int r1=cut1==n?INT_MAX:arr1[cut1];
         int r2=cut2==m?INT_MAX:arr2[cut2];
         
         if(l1<=r2 and l2<=r1)  return max(l1,l2);
         else if(l1>r2) hi=cut1-1;
         else lo=cut1+1;
     }
     return 1;
    }
};

//ALLOCATE BOOKS

bool isPossible(vector < int > & A, int pages, int students) {
  int cnt = 0;
  int sumAllocated = 0;
  for (int i = 0; i < A.size(); i++) {
    if (sumAllocated + A[i] > pages) {
      cnt++;
      sumAllocated = A[i];
      if (sumAllocated > pages) return false;
    } else {
      sumAllocated += A[i];
    }
  }
  if (cnt < students) return true;
  return false;
}
int Solution::books(vector<int> &A, int B) {
    if (B > A.size()) return -1;
    int low = A[0];
    int high = 0;

    for (int i = 0; i < A.size(); i++) {
        high = high + A[i];
        low = min(low, A[i]);
    }

    while (low <= high) {
        int mid = (low + high) >> 1;
        if (isPossible(A, mid, B)) {
        high = mid - 1;
        } else {
        low = mid + 1;
        }
    }
    return low;
}
//HEAPS
//k largest,kth largest
vector<int> Solution::solve(vector<int> &A, int B) {
    priority_queue<int,vector<int>,greater<int>> minH;
    vector<int> res;
    
    for(auto x:A){
        minH.push(x);
        if(minH.size()>B)   minH.pop();
    }
    while(!minH.empty()){
        res.push_back(minH.top());
        minH.pop();
    }
    return res;
}
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minH;
        
        for(int i=0;i<nums.size();i++){
            
            minH.push(nums[i]);
            
            if(minH.size()>k){
                
                minH.pop();
                
            }   
        }
        
        return minH.top(); 
    }
};