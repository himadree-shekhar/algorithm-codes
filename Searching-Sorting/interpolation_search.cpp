#include <iostream>
using namespace std;
/* Interpolation Search: 
	1. Works on Sorted Array.
	2. Uniformly Distributed Array.
	3. Improvement over Binary Search.
	3. Average case: O(log(log n)) If Uniformly Distributed Array.
	4. Worst Case: O(n)
	5. How humans search through a Telephone Book for a Particular Name.
	
	Math: Linear interpolation Formula:
		  (y-y1)/(x-x1) = (y2-y1)/(x2-x1)
		  
		  Let x = Numbers; y = Indexes;
		   Mapping
		   (x, y)   => (x, pos);  
		   (x1,y1)  => (A[lo] , lo);  
		   (x2,y2)  => (A[hi] , hi); 
		 
		  Therfore, (y-y1)/(x-x1) = (y2-y1)/(x2-x1)
		  			=> (pos-lo)/(x-A[lo]) = (hi-lo)/(A[hi]-A[lo])		  			
		  			=>  pos = lo + (x-A[lo])*(hi-lo)/(A[hi]-A[lo])
*/

// Search key
int interpolation_search(int arr[], int size, int key){
	int hi,lo,pos;
	hi = size-1;
	lo = 0;
	
	while(lo <= hi && key >= arr[lo] && key <= arr[hi] ){
		pos = lo + (key-arr[lo])*(hi-lo)/(arr[hi]-arr[lo]);
		
		if(arr[pos] == key)
			return pos;
		else if(arr[pos] < key) // If key is larger, then key is in upper part
			lo =  pos + 1;	
		else // otherwise key is in lower part		
			hi =  pos - 1;
	}
	
	return -1; //if number key not found
}
int main() {
	// your code goes here
	// Array of items on which search will
    // be conducted.
    int arr[] =  {10, 12, 13, 16, 18, 19, 20, 21, 22, 23,
                  24, 33, 35, 42, 47};
				  
				   
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 19; //key Element to be searched
    
    int index = interpolation_search(arr, n, x);
    
 	cout << "Interpolation Search output: " << index << endl;
 	
	return 0;
}