//Binary Search---1. Nth root of M
#include <bits/stdc++.h> 
double multiply(double num,int n){
    double res=1.0;
    for(int i=1;i<=n;i++)
        res*=num;
    return res;
}
double findNthRootOfM(int n, int m) {
	// Write your code here.
    double l=1;
    double hi=m;
    double val=1e-7;
    while((hi-l)>val){
        double mid=(l+hi)/2;
        if(multiply(mid,n)<m)    l=mid;
        else hi=mid;
    }
    
//     double p=1/(double)n;
//     return pow(m,p);
    return hi;
}