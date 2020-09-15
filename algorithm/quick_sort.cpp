// Ref: https://www.geeksforgeeks.org/quick-sort/
#include<iostream>
#define SIZE 7
using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high)
{
	// pivot is element to be placed at right position
	int pivot = arr[high];
	
	// i is index that element smaller than pivot
	// was placed right before.
	int i = low - 1;
	
	for(int j=low; j<=high-1; j++){
		if(arr[j] < pivot){
			swap(&arr[++i], &arr[j]);
		}
	}
	
	swap(&arr[i+1], &arr[high]);
	return i + 1;
}

void quickSort(int arr[], int low, int high)
{
	if(low < high){
		// pi is partitioning index.
		// arr[pi] is now at right place.
		int pi = partition(arr, low, high);
		
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main()
{
	int arr[SIZE] = {10, 80, 30, 90, 40, 50, 70};
	quickSort(arr, 0, SIZE - 1);
	
	for(int i=0; i<7; i++){
		printf("%d ", arr[i]);
	}
}
