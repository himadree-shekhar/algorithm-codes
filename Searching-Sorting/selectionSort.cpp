#include <iostream>
using namespace std;

/*
The algorithm maintains two subarrays in a given array.
1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.

Time Complexity: O(n2) as there are two nested loops.
*/

void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int size){
	//loop for One by one Reduce boundary of Unsorted subarray
	// i < size-1 Because last postion will be sotred
	for(int i=0; i<size-1; i++){
		//loop for Scaning inside Unsorted Sub-Array
		for(int j=i+1; j<size; j++){
			if(arr[j] <= arr[i]){
					swap(&arr[j],&arr[i]);	
			} 
		}
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    cout <<"Ascending Order Sorted Array: "<< endl;
    for (i=0; i < size; i++)
    	cout << arr[i] <<" ";
        
}
 
int main() {
	// your code goes here
	int arr[] = {64, 25, 1,12, 22, 11};
	int n = sizeof(arr)/ sizeof(arr[0]);
	selectionSort(arr, n);
	printArray(arr, n);
	return 0;
}
