#include <iostream>
using namespace std;

/* radixsort overall time complexity O((n+b) * logb(k))
   d -> digits in input integers.
   b -> the base.
   k -> maximum possible value.
*/

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n){
	int max = arr[0];
	for(int i=0; i<n; i++){
		if(arr[i]>max)
			max = arr[i];
	}
	return max;
}

/* A function to do counting sort of arr[] according 
   to the digit represented by exp.
 */
void countSort(int arr[], int n, int exp){
	int output[n];
	int count[10] = {0};
	
	// Store count of occurrences in count[]	
	for(int i=0; i<n; i++){
		count[(arr[i]/exp)%10]++;
	}
	
	/* Change count[i] so that count[i] now contains actual
       position of this digit in output[]
    */   
	for(int i=1; i<10; i++){
		count[i] += count[i-1];
	}
	// Build the output array
	for(int i=n-1; i>=0; i--){
		output[count[(arr[i]/exp)%10]-1] = arr[i];
		count[(arr[i]/exp)%10]--;
	}	
	
	// Copy the output array to arr[]
	for(int i=0; i<n; i++){
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
void radixsort(int arr[], int n){
	// Find the maximum number to find maximum number of digits
	int max = getMax(arr,n);
	
	for(int exp = 1; max/exp >0; exp = exp*10){
		countSort(arr, n,exp);
	}
}
int main() {
	// your code goes here
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixsort(arr, n);
    printArray(arr, n);
	return 0;
}