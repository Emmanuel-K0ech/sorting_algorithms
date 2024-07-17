#include "sort.h"
#include <stdio.h>
/**
 * swap_in_asc - change two values in ascending or descending order
 * @arr: array
 * @x: item one
 * @y: item two
 * @order: 1: ascending order, 0 descending order
 */
void swap_in_asc(int arr[], int x, int y, int order)
{
	int temp;

	if (order == (arr[x] > arr[y]))
	{
		temp = arr[x];
		arr[x] = arr[y];
		arr[y] = temp;
	}
}
/**
 * merge - sort bitonic sequences recursively - in both orders
 * @arr: array
 * @low: first element
 * @n_elements: elements number
 * @order: 1: ascending order, 0 descending order
 */
void merge(int arr[], int low, int n_elements, int order)
{
	int mid, i;

	if (n_elements > 1)
	{
		mid = n_elements / 2;
		for (i = low; i < low + mid; i++)
			swap_in_asc(arr, i, i + mid, order);
		merge(arr, low, mid, order);
		merge(arr, low + mid, mid, order);
	}
}
/**
 * bit_sort - bitonic sort algorithm implementation
 * @arr: array
 * @low: first element
 * @n_elements: number of elements
 * @order: 1: ascending order, 0 descending order
 * @size: array lenght
 */
void bit_sort(int arr[], int low, int n_elements, int order, int size)
{
	int mid;

	if (n_elements > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", n_elements, size);
			print_array(&arr[low], n_elements);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", n_elements, size);
			print_array(&arr[low], n_elements);
		}
		mid = n_elements / 2;
		bit_sort(arr, low, mid, 1, size);
		bit_sort(arr, low + mid, mid, 0, size);
		merge(arr, low, n_elements, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", n_elements, size);
			print_array(&arr[low], n_elements);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", n_elements, size);
			print_array(&arr[low], n_elements);
		}
	}
}
/**
 * bitonic_sort - prepare the terrain to bitonic sort algorithm
 * @array: array
 * @size: array lenght
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	bit_sort(array, 0, size, order, size);
}
