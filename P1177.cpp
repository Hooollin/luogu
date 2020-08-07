#include <bits/stdc++.h>
using namespace std;

void swap(int *arr, int i, int j){
	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}
int partition(int *arr, int l, int r){
	int key = arr[(l + r) / 2];
	swap(arr, l, (l + r) / 2);
	int i = l, j = r;
	while(i < j){
		while(i < j && arr[j] > key){
			j--;
		}
		arr[i] = arr[j];
		while(i < j && arr[i] <= key){
			i++;
		}
		arr[j] = arr[i];
	}
	arr[i] = key;
	return i;
}

void quick_sort(int *arr, int l, int r){
	if(l < r){
		int pivot = partition(arr, l, r);
		quick_sort(arr, l, pivot - 1);
		quick_sort(arr, pivot + 1, r);
	}
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	bool sorted = true;
	for(int i = 0; i < n - 1; i++){
		if(arr[i] > arr[i + 1]){
			sorted = false;
		}
	}
	if(!sorted){
		quick_sort(arr, 0, n - 1);
	}
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}