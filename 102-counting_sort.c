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
	unsigned int x = 0;
	char *p;

	if (no_of_elem == 0 || size == 0)
		return (NULL);
	p = malloc(no_of_elem * size);
	if (p == NULL)
		return (NULL);
	for (x = 0; x < (no_of_elem * size); x++)
		p[x] = '\0';
	return (p);
}
/**
 * counting_sort - this is a counting sort method implementation
 * @array: array to sort
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int indx, max = 0, *counter = NULL, *temp = NULL;
	size_t i;

	if (array == NULL || size < 2)
		return;
	/* find max number */
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	counter = __calloc(max + 1, sizeof(int));
	temp = __calloc(size + 1, sizeof(int));
	/* count the array elements */
	for (i = 0; i < size; i++)
		counter[array[i]]++;
	/* get the accumulative values */
	for (indx = 1; indx <= max; indx++)
		counter[indx] += counter[indx - 1];
	print_array(counter, max + 1);
	/* get the new array sorted */
	for (i = 0; i < size; ++i)
	{
		temp[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}
	/* replace old array to new array sorted */
	for (i = 0; i < size; i++)
		array[i] = temp[i];
	free(temp);
	free(counter);

}
