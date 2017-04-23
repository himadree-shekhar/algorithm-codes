#include <iostream>
using namespace std;
//Time complexity of shellsort is O(n2)
int shellSort(int arr[], int n){
	// select gap 
	for(int gap=n/2; gap>0; gap/=2){
		//do gapped insertion sort
		for(int i=gap; i<n; i++){
			int temp = arr[i];
			// do right gapped sift for greater number
			int j;
			for(j=i; j >= gap && arr[j-gap]>temp; j-= gap){
				arr[j] = arr[j-gap];
			}
			//insertion
			arr[j] = temp;
		}
	}
	
	return 0;
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
}
 
int main()
{
    int arr[] = {12, 34, 54, 2, 3}, i;
    int n = sizeof(arr)/sizeof(arr[0]);
 
    cout << "Array before sorting: \n";
    printArray(arr, n);
 
    shellSort(arr, n);
 
    cout << "\nArray after sorting: \n";
    printArray(arr, n);
 
    return 0;
}