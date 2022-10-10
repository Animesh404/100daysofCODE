#include<bits/stdc++.h>
using namespace std;
//1
//banker and stocks
 int countDivisors(int n) { 
    int cnt = 0; 
    for (int i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            // If divisors are equal, 
            // count only one 
            if (n / i == i) 
                cnt++; 
  
            else // Otherwise count both 
                cnt = cnt + 2; 
        } 
    } 
    return cnt; 
} 
string solution(long n) {
    // Write solution here
	int x=countDivisors(n);
    if(x%2==0)
    return "BUYS";
    else
    return "SELLS";
   
    return "";
}
 
int main() {
	long n;
	cin >> n;	
  	string answer=solution(n);
	cout << answer << endl;
    
}

//2
//guess number

class Solution {
public:
    int guessNumber(int n) {
        int l=1,r=n;
        while(l<=r){
            int m=l+(r-l)/2;
            int g=guess(m);
            if(g==0)
                return m;
            else if(g>0)
                l=m+1;
            else
                r=m-1;
        }
        return -1;
        
    }
};

//3
//first bad version

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1,r=n;
        while(l<=r){
            int m=l+(r-l)/2;
            if(isBadVersion(m)==1)
                r=m-1;
            else
                l=m+1;
        }
        return l;
    }
};

//4
//find peak element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        int l = 1;
        int r = n-1;
        
        while(l <= r) {
            int mid = l + (r - l)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            else if(nums[mid] < nums[mid-1]) r = mid - 1;
            else if(nums[mid] < nums[mid+1]) l = mid + 1;
        }
        return -1;
    }
};

//5
//sql- day2

select employee_id, case when MOD(employee_id,2) =0 or name LIKE "M%" then 0 else salary end as  bonus
from employees order by 1;

//6
//sql-day 2

update salary 
set sex = if(sex='f','m','f');

//or

update salary 
set sex= 
(case 
when sex='f' then 'm' 
else 'f'
end);

//7
//sql-day 2

delete p1 from person p1,person p2 
where p1.email=p2.email and p1.id > p2.id;

//8
//sql

select firstName, lastName, city, state 
from person as p 
LEFT JOIN
address as a on p.personId = a.personId;

//9
//duplicate detection

select email 
from Person 
group by email 
having 
count(email) > 1;


