#include <iostream>

using namespace std;
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r){
    int i,j,k;
    //  lenght : m+1 => (m-l) + 1
    int n1 = m - l + 1;
    int L[n1];
    
    
    //  lenght : r+1 => (r-(m+1)) + 1 => r-m-1+1 => r-m
    int n2 = r - m;
    int R[n2];
    
    for(i=0; i<n1; i++)
        L[i] = arr[l+i]; 
        
    for(j=0; j<n2; j++)
        R[j] = arr[m + 1 + j];    
        
    //Like a Pile of Playing Cards    
    //Pick from the pile
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    /* Copy the remaining elements of L[], if there are any */
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    
    /* Copy the remaining elements of R[], if there are any */
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

// look at binary tree height logn with n numbers in each level
// Time Theta(nLogn) 
void mergeSort(int arr[], int left, int right){
    
    if(left<right){
        // Instead of (right+left)/2. It Avoid Overflow on large l,r  > 2^32-1
       int mid = left + (right-left)/2;
        //left-half
        mergeSort(arr, left, mid);
        //right-half
        mergeSort(arr, mid+1, right);
        
        merge(arr, left, mid, right);
        
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
    
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Given array is: "<<endl;
    printArray(arr, arr_size);
    mergeSort(arr, 0, arr_size - 1);
    cout<<"Sorted array: "<<endl;
    printArray(arr, arr_size);
    return 0;
}
