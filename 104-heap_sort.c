#include "sort.h"
#include <stdio.h>

/**
 * int_swap - utility function to swap to integers
 * @x: integer x
 * @y: integer y
 **/
void int_swap(int *x, int *y)
{
	int i = *x;

	*x = *y;
	*y = i;
}

/**
 * max_Heap - The main function to heapify a Max Heap. The function
 * assumes that everything under given root (element at index idx)
 * is already heapified
 * @array: array
 * @size: size of the array for print
 * @idx: index
 * @n: size of the array to run
 */
void max_Heap(int *array, size_t size, int idx, size_t n)
{
	int largest = idx;		 /* Initialize largest as root*/
	int left = 2 * idx + 1;	 /* left = (idx << 1) + 1*/
	int right = 2 * idx + 2; /* right = (idx + 1) << 1*/

	/* See if left child of root exists and is greater than root*/
	if (left < (int)n && array[left] > array[largest])
		largest = left;

	/**
	 * See if right child of root exists and is greater than
     *the largest so far
	 */
	if (right < (int)n && array[right] > array[largest])
		largest = right;

	/* Change root, if needed*/
	if (largest != idx)
	{
		int_swap(&array[idx], &array[largest]);
		print_array(array, size);
		max_Heap(array, size, largest, n);
	}
}

/**
 * heap_sort -  The main function to sort an array of given size
 * @array: array to sort
 * @size: size of the array
 **/
void heap_sort(int *array, size_t size)
{
	int i;
	/**
	 * Start from bottommost and rightmost internal mode and heapify all
     * internal modes in bottom up way
	 */
	if (array == NULL || size < 2)
		return;

	for (i = (size - 2) / 2; i >= 0; --i)
		max_Heap(array, size, i, size);

	/**
	* Repeat following steps while heap size is greater than 1.
    * The last element in max heap will be the minimum element
	*/
	for (i = (size - 1); i > 0; --i)
	{
		/**
		* The largest item in Heap is stored at the root. Replace
		*it with the last item of the heap followed by reducing the
		*size of heap by 1.
		*/
		int_swap(&array[0], &array[i]);
		print_array(array, size);

		/* Finally, heapify the root of tree.*/
		max_Heap(array, size, 0, i);
	}
}
