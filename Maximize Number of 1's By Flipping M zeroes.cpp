/*
	Input:   arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1}
         m = 2
	Output:  5 7
	We are allowed to flip maximum 2 zeroes. If we flip
	arr[5] and arr[7], we get 8 consecutive 1's which is
	maximum possible under given constraints 

	Input:   arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1}
		 m = 1
	Output:  7
	We are allowed to flip maximum 1 zero. If we flip 
	arr[7], we get 5 consecutive 1's which is maximum 
	possible under given constraints.

	Input:   arr[] = {0, 0, 0, 1}
		 m = 4
	Output:  0 1 2
	Since m is more than number of zeroes, we can flip
	all zeroes.
	
*/
#include<iostream>
using namespace std;

int main() {
	//code
	int t,n,m,m1,i;
	cin>>t;              // No of test cases
	while(t--)
	{
	    cin>>n;          // no of elements(Only 1 and 0) in array)
	    int a[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];     // scan the elements
	    }
	    cin>>m;           // no of zeroes allowed to be flipped
	    m1=m;
	    for(i=0;i<n&&m1;i++)          // finding index of first 1 after m zeroes
	    {
	        if(a[i] == 0)
	        {
	            m1--;
	        }
	    }
	    if(i==n)                 // if zeroes present in array are less than m then whole array length is answer
	    {
	        cout<<n<<endl;
	        continue;
	    }
	    int start = 0;
	    int curr = i;
	    int max = -1;
	    while(curr<n)            // here sliding window techique is used,curr will start from first 1 after first m zeroes
	    {
	        if(a[curr] == 0)     // if zero is found that means we have found m+1 zeroes from start,so update max now
	        {
	            max = max > (curr-start) ? max : (curr-start);
	            for(;a[start]!=0;start++){}         // move the start from first 0 of m zeroes to next element
	            start++;
	        }
	        else if(curr == n-1)        // if we are at last element and after m zeroes from start (m+1)th zero is not found then update max
	        {
	            max = max > (curr-start+1) ? max : (curr-start+1);
	        }
	        curr++;
	    }
	    cout<<max<<endl;
	   // max = max > curr-start ? max : curr-start;
	}   
	return 0;
}
