#include "ft.h"

#define MAP_SIZE 20

int is_sq_possible(int **arr, int x, int y, int size,int height, int width)
{
	int i = 0;
	int j = 0;

	if (x + size > width || y + size > height)
		return (0);
	while (x + i <= width && i < size)
	{
		j = 0;
		while (y + j <= height && j < size)
		{
			if (arr[y + j][x + i] == 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void place_square(int **arr, int *best)
{
	int i = 0;
	int j = 0;
	while (j < best[2])
	{
		i = 0;
		while (i < best[2])
		{
			arr[best[1] + j][best[0] + i] = 2;
			i++;
		}
		j++;
	}
}

void solve(int **arr, int *best, int height, int width)
{
	int i = 0;
	int j = 0;
	int size = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			while (1)
			{
				if (arr[j][i] == 1)
				{
					break;
				}
				if (is_sq_possible(arr, j, i, size, height, width))
				{
					if (size > best[2])
					{
						best[0] = j;
						best[1] = i;
						best[2] = size;
					}
					size++;
				}
				else
				{
					break;
				}
			}
			j++;
		}
		i++;
	}
}

int fill_map(int x, int y, int **map)
{
	if (map[y][x] != 1)
	{
		map[y][x] = 1;
		return (1);
	}
	else
	{
		return (-1);
	}
}


ft_array algo(ft_array arr)
{
	int *best;
	//int size = MAP_SIZE;

	best = malloc(sizeof(int) * 3);
	best[0] = 0;
	best[1] = 0;
	best[2] = 0;

	// arr = malloc(sizeof(int *) * size + 1);
	int i = 0;
	int j = 0;
	// while (i < size)
	// {
	// 	arr[i] = malloc(sizeof(int) * size + 1);
	// 	j = 0;
	// 	while (j < size)
	// 	{
	// 		arr[i][j] = 0;
	// 		j++;
	// 	}
	// 	arr[i][j] = -1;
	// 	i++;
	// }
	// arr[i] = malloc(sizeof(int));
	// arr[i][0] = -1;
	// i = 0;
	// j = 0;

	// fill_map(5,5,arr);
	// fill_map(11,11,arr);
	// fill_map(4,17,arr);
	// fill_map(5,10,arr);
	// fill_map(15,0,arr);



	// while (arr[i][0] != -1)
	// {
	// 	while (arr[i][j] != -1)
	// 	{
	// 		printf("%d", arr[i][j]);
	// 		j++;
	// 	}
	// 	j = 0;
	// 	printf("\n");
	// 	i++;
	// }
	solve(arr.array, best,arr.size[1], arr.size[0]);
	printf("x: %d y: %d size: %d", best[0], best[1], best[2]);
	place_square(arr.array,best);
	i = 0;
	j = 0;
	return arr;
}

