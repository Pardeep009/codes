/*
	Given an array containing N integers and an integer K. Task is to find the length of the longest Sub-Array with sum of
	the elements equal to the given value K.
	
	Input : arr[] = { 10, 5, 2, 7, 1, 9 }, 
	K = 15
	Output : 4
	The longest sub-array is {5, 2, 7, 1}.
	
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t,n,k;
	cin>>t;           // no of test cases
	while(t--)
	{
	    cin>>n>>k;       // no of elements in array and k
	    unordered_map<int,int> map;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    int sum = 0;
	    int max = 0;
	    map[0] = -1;
	    for(int i=0;i<n;i++)
	    {
	        sum+=a[i];                // sum till ith index in the array
	        if(map.find(sum-k)!=map.end())           // finding sum-k in map
	        {
	            max = max > (i-map[sum-k]) ? max : (i-map[sum-k]);        // if present check its index and update max variable
	        }
	        if(map.find(sum)==map.end())               // if sum not present then insert it
	            map[sum] = i;
	    }
	    cout<<max<<endl;                // longest sub array length
	}
	return 0;
}
