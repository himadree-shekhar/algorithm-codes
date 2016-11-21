#include <iostream>
using namespace std;
int binarySearchRecursive(int arry[], int l, int r, int num){
	//Notice:Only Works For Sorted Arrayi in Ascending Order
    if(l<=r){
    	int mid = l + (r-l)/2;
    	if(arry[mid]==num) return mid; 
    	if(arry[mid] > num) return binarySearchRecursive(arry, l, mid-1, num);
    	return binarySearchRecursive(arry, mid+1, r, num);
    	
    }
    return -1;
}
int main() {
	//For Binary Search, Recurrence Relation T(N) = T(N/2) + O(1) = O(log(N))
	// your code goes here
	int array[] = {1,2,3,4,5};
	int search_num = 5;
	cout << "Output: "<<binarySearchRecursive(array, 0, 4, search_num);
	return 0;
}