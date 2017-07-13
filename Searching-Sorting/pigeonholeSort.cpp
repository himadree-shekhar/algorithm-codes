#include <iostream>
#include <vector>
using namespace std;
/*
the number of elements (n) and 
the length of the range of possible key values (Range)
are approximately the same
Ex: if n=10, min=90, max=100, Range = max-min-1 = 100-90-1= 9
so, n & Range are approximately the same
It requires O(n + Range) time
*/
 
/* Sorts the array using pigeonhole algorithm */
void pigeonholeSort(int arr[], int n)
{
	// step-1: find max,min in the input array
	int max=arr[0];
	int min=arr[0];
	for(int i=0; i<n; i++){
		if(arr[i]<min)
			min = arr[i];
		if(arr[i]>max)
			max = arr[i];	
	}
	
	// step-2: find range from max,min
	/*
		to index from 0......to [max-min] = max-min+1 
		that is why range = max-min+1;
	*/
	int range = max-min+1;
	
	// step-3 create pigeonhole of size range
	vector<int>pigeonhole[range];
	
	/* Traverse through input array and put every
       element in its respective hole
       arr[i]-min is mapping from min-based index into 0-based index
       
    */
	for(int i=0; i<n; i++){
		pigeonhole[arr[i]-min].push_back(arr[i]);
	}
	
	/* Traverse through all holes one by one. For
       every hole, take its elements and put in array.
    */   
	int index = 0;
	for(int i=0; i<range; i++){
		vector<int>::iterator it; // :: is for global scope
		for(it=pigeonhole[i].begin(); it !=pigeonhole[i].end();  it++)
			arr[index++] = *it;
	}
}
int main() {
	// your code goes here
	int arr[] = {8, 3, 2, 7, 4, 6, 8};
	int size = sizeof(arr)/sizeof(arr[0]);
	pigeonholeSort(arr, size);
	cout<<"Sorted order is : ";
    for (int i = 0; i < size; i++)
    	cout<<arr[i]<<" ";
    	
	return 0;
}