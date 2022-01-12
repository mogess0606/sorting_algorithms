#include "sort.h"
#define up 1
#define down 0
void bs_helper(int *array, size_t size, size_t subsize, size_t idx, int dir);
void bs_merge(int *array, size_t size, size_t subsize, size_t idx, int dir);
void cmpswap(int *array, size_t i, size_t j, int dir);
/**
 * bitonic_sort - bitonic sort on array
 * @array: array
 * @size: size
 */
void bitonic_sort(int *array, size_t size)
{
	bs_helper(array, size, size, 0, up);
}
/**
 * bs_helper - bitonic sort helper
 * @array: array
 * @size: size of array
 * @subsize: size of sub array
 * @idx: start index of sub array
 * @dir: direction (up or down)
 */
void bs_helper(int *array, size_t size, size_t subsize, size_t idx, int dir)
{
	size_t sub = subsize / 2;

	if (subsize > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n",
		       subsize, size, dir ? "UP" : "DOWN");
		print_array(array + idx, subsize);
		bs_helper(array, size, sub, idx, up);
		bs_helper(array, size, sub, idx + sub, down);
		bs_merge(array, size, subsize, idx, dir);
	}
}
/**
 * bs_merge - bs merger
 * @array: array
 * @size: size of array
 * @subsize: size of sub array
 * @idx: start index of sub array
 * @dir: direction
 */
void bs_merge(int *array, size_t size, size_t subsize, size_t idx, int dir)
{
	size_t gap, i;

	for (gap = subsize / 2; gap > 0; gap--)
		for (i = idx; i < subsize - gap + idx; i++)
			cmpswap(array, i, i + gap, dir);
	printf("Result [%lu/%lu] (%s):\n",
	       subsize, size, dir == up ? "UP" : "DOWN");
	print_array(array + idx, subsize);
}
/**
 * cmpswap - compare and swap
 * @array: array
 * @i: i
 * @j: j
 * @dir: direction
 */
void cmpswap(int *array, size_t i, size_t j, int dir)
{
	int tmp;

	if (dir == (array[i] > array[j] ? 1 : 0))
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}
