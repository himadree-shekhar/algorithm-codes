#include <iostream>
#include <math.h>
using namespace std;
int jumpSearch(int arr[], int num, int size){
	
	//size of the Block
	int block_size = sqrt(size);
	
	int prev = 0;
	int block = block_size;
	//selecting block range Where arr[prev] < x < arr[block-1]
	while(arr[block-1] < num){
	   	prev = block;
		block += block_size;
		
		if(prev == size){
			
			return -1;
		}
		
	}
	
	//linear search in seleted block range: array[km] to array[(k+1)m]
	while(arr[prev] < num){
		prev ++;
		if(prev == size){
			return -1;
		}
	}
	
	
	if(arr[prev] == num){
			return prev;
	}
	
	return -1;
}

int main() {
	// your code goes here
	 int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21,
                     34, 55, 89, 144, 233, 377, 610};
        int x = 55;
 		int n = sizeof(arr)/sizeof(arr[0]);	
        
        // Find the index of 'x' using Jump Search
        int index = jumpSearch(arr, x, n);
        
        cout<<"Output: "<<index;
        
	return 0;
}