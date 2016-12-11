#include <iostream>
using namespace std;

/*
always runs O(n^2).
Optimized Implementation:  
stopping the algorithm if inner loop didn’t cause any swap.
*/
void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void bubbleSort(int arr[], int size){
	bool isSwap;
	// i<size-1 Because Maximum Possible Bubbles => size-1 
	for(int i=0; i<size-1; i++){
		// j<size-1-i Because Right part Is getting Sorted
		for(int j=0; j<size-1-i; j++){
				if(arr[j] > arr[j+1]){
					 swap(&arr[j], &arr[j+1]);
					 //Optimized Solution
					  isSwap = true;
				}
	    }
	    //Optimized Solution
		if(isSwap == false){
			break;
		}
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
	int arr[] = {64, 34, 11,25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr, n);
	printArray(arr, n);
	return 0;
}