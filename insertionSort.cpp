#include <iostream>
using namespace std;
/*
 1. Insertion sort like we sort playing cards in our hands.
 2. Time Complexity: O(n^2)
 */

// Ascending Order 
void insertionSort(int arr[], int n){
	// starts with second index since first is sorted by dafault
	int key, j;
	for(int i=1; i<n; i++){
		key = arr[i];
		j=i-1;
		//right shifting bigger numbers 
		while(j >= 0 && arr[j] > key){
				// arr[j+1] is Not lost since key has its copy
				arr[j+1] = arr[j];	
				j--;
		}
		arr[j+1] = key;
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
	int arr[] = {1,3,4,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    
	insertionSort(arr, n);
	printArray(arr, n);
	
	return 0;
}
