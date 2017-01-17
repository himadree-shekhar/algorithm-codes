#include <iostream>
using namespace std;
/*  History:  Developed by Tony Hoare in 1959
	Different versions of quickSort  picks pivot in different ways:
    1. Always pick first element as pivot.
    2. Always pick last element as pivot (implemented below)
    3. Pick a random element as pivot.
    4. Pick median as pivot.
	
	Average Case: O(nLogn)
	Worst Case:O(n^2)
*/

void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high){
	//pick last element of the array as pivot
	int pivot = arr[high];
	int i = low - 1;
	//loop to pick elements before pivot index
	for(int j=low; j<=high-1; j++){
		if(arr[j] <= pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	
	return (i+1);
}


/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high){
	int pi;
	if(low<high){
		pi = partition(arr, low, high);
		quickSort(arr, low,  pi-1);
		quickSort(arr, pi+1, high);
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
	int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
	return 0;
}