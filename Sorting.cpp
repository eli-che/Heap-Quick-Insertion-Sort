#ifndef SORT_H
#define SORT_H
#pragma once
#include <algorithm>



template<typename T>
void insertionsort(T arr[], int n) {
	int index;
	T currentValue;
    for (int i = 1; i < n; ++i) {
        currentValue = arr[i];
        index = i - 1;
        while (index >= 0 && arr[index] > currentValue) {
            arr[index + 1] = arr[index];
            index = index - 1;
        }
        arr[index + 1] = currentValue;
    }
}


template <typename T> int partition(T* arr, int less, int higher)
{
	T punkt = arr[higher];
	int i = (less - 1);
	for (int j = less; j <= higher - 1; j++)
	{
		if (arr[j] < punkt)
		{
			i++; 
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[higher]);
	return (i + 1);
}


template <typename T> void quicksort(T* arr, int less, int high)
{
	if (less < high)
	{
		int pivot = partition(arr, less, high);
		quicksort(arr, less, pivot - 1);
		quicksort(arr, pivot + 1, high);
	}
}

template <typename T>void quicksort(T arr[], int n) {

	quicksort(arr, 0, n - 1);

}

template <typename T>
void heapify(T arr[], int index, int pass) {
	T temporary;
	int greater = pass;
	int l = 2 * pass + 1;
	int r = 2 * pass + 2;
	if (l < index && arr[l] > arr[greater])
		greater = l;
	if (r < index && arr[r] > arr[greater])
		greater = r;
	if (greater != pass) {
		temporary = arr[pass];
		arr[pass] = arr[greater];
		arr[greater] = temporary;
		heapify(arr, index, greater);
	}
}

template <typename T>
void heapsort(T arr[], int n) {
	T temporary;
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i >= 0; i--) {
		temporary = arr[0];
		arr[0] = arr[i];
		arr[i] = temporary;
		heapify(arr, i, 0);
	}
}

#endif