// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int A[],int N)
{
//Your code here
int sumOfArray=0;
int productInitial=0;
for(int i=0;i<N;i++)
{
    sumOfArray+=A[i];
    productInitial+=i*A[i];
}
int res=productInitial;
for(int i=1;i<N;i++)
{
    productInitial+=(A[i-1]*N)-sumOfArray;
    res=max(productInitial,res);
}
return res;
}