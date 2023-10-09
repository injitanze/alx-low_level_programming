#include "search_algos.h"

/**
 * linear_search - Searches for a value in an array of
 * integers using the Linear search algorithm
 *
 * @array: Input array
 * @size: Size of the array
 * @value: Value to search 
 * Return: Always EXIT_SUCCESS
 */

int linear_search(int *array, size_t size, int value)
{
	size_t x;

	if (array == NULL)
	{
		return (-1);
	}

	for (x = 0; x < size; x++)
	{
		printf("Value checked array[%li] = [%i]\n", x, array[x]);
		if (array[x] == value)
		{
			return (x);
		}
	}
	return (-1);
}
