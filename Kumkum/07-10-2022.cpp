#include<bits/stdc++.h>
using namespace std;

//1
//valid perfect square
class Solution {
public:
    bool isPerfectSquare(int x) {
        int l=0,r=x;
        while(l<=r){
            long long m=l+(r-l)/2;
            if((m*m)==x)
                return true;
            else if((m*m)>x)
                r=m-1;
            else
                l=m+1;
        }
        return false;
    }
};

//2
//sql-day 1

select name, population, area from World where  population>=25000000 OR area>=3000000;

//3
//sql

select product_id from products where low_fats='Y' and recyclable='Y';

//4
//sql
select name from customer where referee_id!=2 or referee_id is null;

//5
//sql
select name as Customers from customers left join Orders on Customers.id= Orders.customerId where Orders.customerId is null;

//6
//sqrt(x)
class Solution {
public:
    int mySqrt(int x) {
        int l=0,r=x;
        int ans;
        while(l<=r){
            long long m=l+(r-l)/2;
            if(m*m==x)
            {
                ans=m;
                break;
            }
            else if(m*m > x)
                r=m-1;
            else{
                l=m+1;
                ans=m;
            }
        }
        return ans;
        
    }
};


