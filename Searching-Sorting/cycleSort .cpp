#include <iostream>
using namespace std;

/*
	It is an unstable sorting algorithm.
	It minimizes the number of Memory Writes.
	It is based on idea that array to be sorted can be divided into Cycles.
	Time Complexity : O(n2)
*/

// Function sort the array using Cycle sort
void cycleSort (int arr[], int n){
	// count number of memory writes
	int writes = 0;	
	/*
		traverse array elements and put it to on the right place
		Loop runs (n-1)times because last element will automatically sorted
	*/
	
	//We one by one consider all cycles. 
	//We first consider the cycle that includes first element.
	for(int cycle_start=0; cycle_start<n-1; cycle_start++){
		// initialize item as starting point
		int item = arr[cycle_start];
		
		// Find position where we put the item. We basically
        	// count all smaller elements on right side of item.
		int pos = cycle_start;
		for(int i = cycle_start+1; i<n; i++)
			/* if smaller number fund, 
			   then there must be a new position for item 
			 */
			if(arr[i]<item){
				pos++;
			}
			
			// If item is already in correct position
	        if (pos == cycle_start)
	            continue;
            
			while(item==arr[pos]){
			   // no need to overwrite duplicate, so move on next	
			   pos++;
			}
			
			// if pos != cycle_start the there must be new position
			if(pos != cycle_start){
				swap(item, arr[pos]);
				writes++;
				
			}
			
			/*
				if (pos != cycle_start) that means 
				this cycle is still need to rotate rest of the Cycle
			*/
			while(pos != cycle_start){
				pos = cycle_start;
				for(int i = cycle_start+1; i<n; i++)
					/* if smaller number fund, 
					   then there must be a new position for item 
					 */
					if(arr[i]<item){
						pos++;
					}
					
					while(item==arr[pos]){
					   // no need to overwrite duplicate, so move on next	
					   pos++;
					}
					/*
						It can be true pos == cycle_start 
						But at the same time item != arr[pos]
						Ex: item = 2; arr = {10,3,5,10}
						thats why we used if(item != arr[pos])
					*/ 
					if(item != arr[pos]){
						swap(item, arr[pos]);
						writes++;
					}
			}
	}
}

int main() {
	// your code goes here
	int arr[] = {1, 8, 3, 9, 10, 10, 2, 4 };
    int n = sizeof(arr)/sizeof(arr[0]);
    cycleSort(arr,  n) ;
 
    cout << "After sort : " <<endl;
    for (int i =0; i<n; i++)
        cout << arr[i] << " ";
	return 0;
}