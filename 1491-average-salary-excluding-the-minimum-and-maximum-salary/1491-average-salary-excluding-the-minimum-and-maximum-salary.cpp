class Solution {
public:
    double average(vector<int>& salary) 
    {
    
        int a=*min_element(salary.begin(),salary.end());
int b=*max_element(salary.begin(),salary.end());
double f=0;int count=0;
for(auto it:salary)
{
if(it!=a && it!=b)
{
f+=it;
count++;
}
}
return (f/=count);
    }
};