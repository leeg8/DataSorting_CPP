#pragma once
#include <iostream>
using namespace std;
void show(int* array, int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}
void merge(int* array, int left, int middle, int right) {
	int i, j, k, leftSize, rightSize;
	leftSize = middle - left + 1; rightSize = right - middle;
	int* leftArr = new int[leftSize], * rightArr = new int[rightSize];
	for (i = 0; i < leftSize; i++) {
		leftArr[i] = array[left + i];
	}
	for (j = 0; j < rightSize; j++) {
		rightArr[j] = array[middle + 1 + j];
	}
	i = 0; j = 0; k = left;
	while (i < leftSize && j < rightSize) {
		if (leftArr[i] <= rightArr[j]) {
			array[k] = leftArr[i];
			i++;
		}
		else {
			array[k] = rightArr[j];
			j++;
		}
		k++;
	}
	while (i < leftSize) {
		array[k] = leftArr[i];
		i++; k++;
	}
	while (j < rightSize) {
		array[k] = rightArr[j];
		j++; k++;
	}
}
void mergeSort(int* array, int left, int right) {
	int m;
	if (left < right) {
		int m = left + (right - left) / 2;
		// Sort both arrays
		mergeSort(array, left, m);
		mergeSort(array, m + 1, right);
		merge(array, left, m, right);
	}
}