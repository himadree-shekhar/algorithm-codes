//============================================================================
// Name        : Binary_Search_Iterative.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int binray_search(int left, int right, int num, int array[]){
	int mid=0;
	while(left <= right){
		//Avoid Overflow on large l,r  > 2^32-1
		mid = left + (right-left)/2;
		// if number found at mid
		if(num == array[mid])
			return mid;

		// if number is on left side
		else if(num < array[mid])
			right = mid - 1;

		// else number is on right side
		else
			left = mid + 1;
	}
	// number not found
	return -1;

}

int main() {
   // Notice: The code Works Only for Sorted array in Ascending order
	int input_array[] = {1,2,3,4,5};
	int search_num = 4;
    int output = binray_search(0, 4, search_num, input_array);
    cout << "Binary Search Iterative output: "<<output<<endl;
	return 0;
}
