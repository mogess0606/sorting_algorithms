#include "sort.h"
/**
 * find_maxvalue - Finds the number with most digits
 * @array: Array with numbers to be sorted
 * @size: size of the original array
 * Return: The array with the allocation for the copies
 */
int find_maxvalue(int *array, size_t size)
{
	int max_ = array[0];
	size_t i = 1;

	while (i < size)
	{
		if (array[i] > max_)
			max_ = array[i];
		i++;
	}

	return (max_);
}
/**
 * malloc_ - Creates the arrays to be filled
 * @copies: Array to be copied
 * @size: size of the original array
 * Return: The array with the allocation for the copies
 */
int **malloc_(size_t copies, size_t size)
{
	int **array = NULL;
	size_t i = 0;

	array = malloc(sizeof(int *) * copies);
	if (!array)
		return (NULL);
	while (i < copies)
	{
		array[i] = malloc(sizeof(int) * size);
		if (!array[i])
		{
			while (i > 0)
				free(array[i]), i--;
			return (NULL);
		}
		i++;
	}

	return (array);
}
/**
 * array_copy - Copies the array
 * @source: Array to be copied
 * @destiny: Copied array
 * @size: size of the original array
 */
void array_copy(int *source, int *destiny, size_t size)
{
	size_t i = 0;

	while (i < size)
		destiny[i] = source[i], i++;
}
/**
 * radix_sort - sorts the elements by initially grouping the individual
 * digits of the same place value. The idea of Radix Sort is to do digit
 * by digit sort starting from least significant digit(LSD) to the most
 * significant digit(MSD), according to their increasing/decreasing order.
 * @array: Array of data to be sorted
 * @size: size of the original array
 */
void radix_sort(int *array, size_t size)
{
	int max_ = 0, pow_ = 1, **aux, *copy, *copy2, *copy3;
	size_t i = 0, j = 0, k = 0, l = 0;

	if (size < 2)
		return;
	aux = malloc_(3, size);
	if (!aux)
		return;
	copy = aux[0], copy2 = aux[1], copy3 = aux[2];
	max_ = find_maxvalue(array, size);
	array_copy(array, copy2, size);
	while (max_ / pow_ > 0)
	{
		i = 0;
		while (i < size)
			copy2[i] = (array[i] / pow_) % 10, i++;
		i = 0;
		while (i < size)
			copy[i] = copy2[i] % 10, i++;
		j = 0, k = 0;
		while (k <= 9)
		{
			l = 0;
			while (l < size)
			{
				if (copy[l] == (int)k)
				{
					copy3[j] = array[l];
					j++;
				}
				l++;
			}
			k++;
		}
		array_copy(copy3, array, size);
		pow_ *= 10;
		print_array(array, size);
	}
	free(copy), free(copy2), free(copy3), free(aux);
}
