#include <iostream>
using namespace std;

/*
Time Complexity:  heapify is O(Logn) & create Build Heap is O(n) 
               So, overall time complexity of Heap Sort is O(nLogn).
               
               height of heap is logn
*/
// To heapify a subtree rooted with node root which is
// an index in arr[]. n is size of heap

void heapify(int arr[], int n, int root){
	int largest = root;
	int l = 2*root + 1; // left side child index
	int r = 2*root + 2; // right side child index
	
	// Finding greater Value among parent & childs
	if(l<n && arr[l] > arr[largest])
		largest = l;
	
	if(r<n && arr[r] > arr[largest])
		largest = r;
		
	if(largest != root){
		swap(arr[root],arr[largest]);
		heapify(arr, n, largest);		
	}
	
	return;
}

// main function to do heap sort
void heapSort(int arr[], int n){
	// heapify from right most node in 2nd last lavel
	//because last level has no childs
	// Build heap O(n) 
	for(int i= n/2 - 1; i>= 0; i--){
		// arr means &arr[0],Its not arr[] that is used at Initializing Arrays
		heapify(arr, n, i);
	}
	
	for(int i = n-1; i>=0; i--){
		//swap root value with latest large value Because max heap
		swap(arr[0],arr[i]);
		
		/*
			A max-heap is a complete binary tree where each internal node
			is greater than or equal to the values of its children.
		*/
		//makes Descending Order to Ascending order ex: 3,2,1 -> 1,2,3
		heapify(arr, i, 0);
	}
}

void swap(int *p1, int *p2){
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void printArray(int arr[] , int size){
		for(int i=0; i<size; i++){
			cout<<arr[i]<<' ';
		}
		cout<<endl;
}
int main() {
	// your code goes here
	int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
   
    cout << "Unsorted array is \n";
    printArray(arr, n);
    
    // arr means &arr[0],Its not arr[] that is used at Initializing Arrays
    heapSort(arr, n);
    
    cout << "Sorted array is \n";
    printArray(arr, n);
	return 0;
}