#include "sort.h"
#include <stdio.h>
/**
 *__calloc - this is a calloc function
 *@no_of_elem: number of elemets
 *@size: bit size of each element
 *Return: pointer to memory assignement
 */
void *__calloc(unsigned int no_of_elem, unsigned int size)
{
	unsigned int i = 0;
	char *p;

	if (no_of_elem == 0 || size == 0)
		return (NULL);
	p = malloc(no_of_elem * size);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < (no_of_elem * size); i++)
		p[i] = '\0';
	return (p);
}
/**
 *_merge - make a merge
 *@arr: one from start to mid
 *@tmp: temp array used in merge, was created outside to
 *optimize reducing the system calls
 *@start: first element position
 *@mid: array middle
 *@end: last element position
 **/
void _merge(int *arr, int *tmp, int start, int mid, int end)
{
	/*  sizes and temp arrays */
	int size_left = mid - start + 1, size_right = end - mid;
	int *left_array, *right_array;
	/* counters */
	int left, right, i = 0;

	left_array = &tmp[0];
	right_array = &tmp[size_right];
	for (left = 0; left < size_left; left++)
		left_array[left] = arr[start + left];
	for (right = 0; right < size_right; right++)
		right_array[right] = arr[mid + 1 + right];
	left = 0, right = 0, i = start;
	/* merging tmp arrays into main array*/
	while (left < size_left && right < size_right)
	{
		if (left_array[left] <= right_array[right])
			arr[i] = left_array[left], left++;
		else
			arr[i] = right_array[right], right++;
		i++;
	}
	/* merging remaining left array into main array*/
	while (left < size_left)
		arr[i] = left_array[left], left++, i++;
	/* merging remaining right array into main array*/
	while (right < size_right)
		arr[i] = right_array[right], right++, i++;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left_array, left);
	printf("[right]: ");
	print_array(right_array, right);
	printf("[Done]: ");
	print_array(&arr[start], left + right);
}
/**
 *__mergesort - function that sorts an array of integers
 *in ascending order using the Merge sort algorithm
 *@array: array of integers
 *@tmp: temp array used in merge, was created outside to
 *optimize reducing the system calls
 *@start: fisrt element position
 *@end: last element position
 *Return: void
 */
void __mergesort(int *array, int *tmp, int start, int end)
{
	int mid;

	mid = (start + end) / 2;
	if ((start + end) % 2 == 0)
		mid--;
	if (mid >= start)
	{
		__mergesort(array, tmp, start, mid);
		__mergesort(array, tmp, mid + 1, end);
		_merge(array, tmp, start, mid, end);
	}
}
/**
 *merge_sort - function that sorts an array of integers
 *in ascending order using the Merge sort algorithm
 *@size: size of the list
 *@array: array of integers
 *Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;
	tmp = __calloc(size, sizeof(int));
	__mergesort(array, tmp, 0, size - 1);
	free(tmp);
}
