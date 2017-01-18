#include <iostream>
#include <string.h>
using namespace std;
/*
  1 Time Complexity: O(n+k) where 
     n = number of elements in input array 
     k = the range of input.
     
  2. It is not a comparison based sorting. 
  
  3. user need to know  the input sequence in advance.
*/
void countSort(int arr[], int size)
{
	//declare output array
	int output[size];
	//declare count array
	int count[size];
	//initialize count[] with zero
	//memset ( void * ptr, int value, size_t num )
	memset(count, 0, sizeof(count));

	//input array element is the index of count array
	//storing the repetition/frequency
	for(int i=0; i<size; i++){
		count[arr[i]]++;
	}
	
		
	/*
		Modify the count array such that each element at 
		each index stores the sum of previous counts.
	*/
	// i=1 because, previous is 0 due to avoid -1
	for(int i=1; i<size; i++){
		count[i] += count[i-1];
	}
	
	//Build ouput array
	//count array element is the index of output array 
	for(int i=0; i<size; i++){
		//count[arr[i]] is giving cumulative position of the current number
		//count[arr[i]]-1 Zero-based index array position of the current number
		output[count[arr[i]]-1] = arr[i];
		count[arr[i]]--;
	}
	
	//copy ouput array into input array arr[]
	for(int i=0; i<size; i++){
			arr[i] = output[i];
	}

}

void printArray(int arr[], int size){
	// Ascending order
	for(int i=0; i<size; i++){
		cout<<arr[i]<<" ";
	}	
	cout<<endl;
	
}

int main() {
	// your code goes here
	int arr[] = {1,4,1,2,7,5,2,6,6,9};
	int size= sizeof(arr)/sizeof(arr[0]);
	countSort(arr, size);
	printArray(arr, size);
	return 0;
}