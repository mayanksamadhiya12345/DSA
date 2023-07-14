//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// first we will sort the arrival and departure array
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	// for storing the minimum no of platforms and current using platforms
    	int cur_plat = 1;
    	int res = 1;
    	
    	int i = 1;     // for arrival 
    	int j = 0;     // for departure
    	
    	while(i<n && j<n)
    	{
    	    // if arrival time is less than the departure it means we need one more plat
    	    if(arr[i]<=dep[j])
    	    {
    	        cur_plat++;
    	        i++;
    	    }
    	    // if arrival date is greater than the departure date then we can depart one train 
    	    else if(arr[i]>dep[j])
    	    {
    	        cur_plat--;
    	        j++;
    	    }
    	    
    	    // if current platform are greater than result then assijg it inti result
    	    if(res<cur_plat)
    	    {
    	        res = cur_plat;
    	    }
    	}
    	return res;
    }
};


//{ Driver Code Starts.
// Driver code
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
   return 0;
}
// } Driver Code Ends