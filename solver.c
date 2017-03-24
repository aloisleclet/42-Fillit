/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:12:43 by aleclet           #+#    #+#             */
/*   Updated: 2017/03/24 14:42:25 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**alloc_map(char **map, int n)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	map = (char**)malloc(sizeof(char**) * (n + 1));
	while (j < n)
	{
		map[j] = (char*)malloc(sizeof(char*) * (n + 1));
		j++;
	}
	j = 0;
	i = 0;
	while (j < n)
	{
		while (i < n)
		{
			map[j][i] = '.';
			i++;	
		}
		i = 0;
		j++;
	}
	return (map);
}

void	print_map(char **map, int n)
{
	int		j;
	int		i;

	i = 0;
	j = 0;

	while (j < n)
	{
		while (i < n)
		{
			printf("%c", map[j][i]);
			i++;
		}	
		i = 0;	
		j++;
		printf("\n");
	}
	printf("\n");
}

int		limit_map(int pos_x[4], int pos_y[4], int translate_x, int translate_y, int size_map)
{
	int		i;

	i = 0;
	while (i < size_map)
	{
		//printf("i: %d x: %d y: %d\n", i, pos_x[i] + translate_x,  pos_y[i] + translate_y);
		if ((pos_x[i] + translate_x) >= size_map)
		{
		//	printf("limit x\n");
			return (0); //limit x
		}
		else if ((pos_y[i] + translate_y) >= size_map)
		{
		//	printf("limit y\n");
			return (-1); //limit y
		}
		i++;
	}
	return (1);
}

int id = 16;

int		place_found(char **map, int pos_x[4], int pos_y[4], int translate_x, int translate_y)
{
		if (map[pos_y[0] + translate_y][pos_x[0] + translate_x] == '.' &&
		map[pos_y[1] + translate_y][pos_x[1] + translate_x] == '.' &&
		map[pos_y[2] + translate_y][pos_x[2] + translate_x] == '.' &&
		map[pos_y[3] + translate_y][pos_x[3] + translate_x] == '.')
		{
		//	printf("before\n");
		//	print_map(map, 6);
		//	printf("after place-found\n");
			id++;
			map[pos_y[0] + translate_y][pos_x[0] + translate_x] = id + 48; //map[y][x] chelou ..
			map[pos_y[1] + translate_y][pos_x[1] + translate_x] = id + 48;
			map[pos_y[2] + translate_y][pos_x[2] + translate_x] = id + 48;
			map[pos_y[3] + translate_y][pos_x[3] + translate_x] = id + 48;
			//print_map(map, 6);
			return (1);
		}
	//	else
	//	{
	//		map[pos_y[0] + translate_x][pos_x[0] + translate_y] = 'x';
	//		map[pos_y[1] + translate_x][pos_x[1] + translate_y] = 'x';
	//		map[pos_y[2] + translate_x][pos_x[2] + translate_y] = 'x';
	//		map[pos_y[3] + translate_x][pos_x[3] + translate_y] = 'x';
	//		print_map(map, 6);
	//	
	//	}
		return (0);
}

int		put_tetri_on_map(int pos_x[4], int pos_y[4], char **map, int size_map)
{
	int		translate_x;
	int		translate_y;

	translate_x = 0;
	translate_y = 0;
	while (translate_y < size_map && !place_found(map, pos_x, pos_y, translate_x, translate_y))
	{
//		printf("no-place\n");
		if (limit_map(pos_x, pos_y, translate_x, translate_y, size_map) == 0)
		{
			translate_x = 0;
			translate_y++;
		}
		if (limit_map(pos_x, pos_y, translate_x, translate_y, size_map) == -1)
		{
			return (0);
		}	
		else
			translate_x++;
//		printf("translate x: %d y: %d \n", translate_x, translate_y);
	}
	
//	printf("end put_tetri_on_map\n");
	print_map(map, size_map);
	return (1);
//todo
//tant qu'il y'a pas de # ou que je suis pas le plus en haut a gauche possible, decaler tetris
// return 1 if the tetris find place
// return 0 if the tetris have no place
// return -1 if there is an error
}

int		solve(char ***table, int n)
{
	int		i;
	int		size;
	int		pos_x[4];
	int		pos_y[4];
	char	**map;

	size = 3;
	i = 0;
	map = NULL;
	
	printf("solving...\n");
	map = alloc_map(map, size);
	print_map(map, size);
	while (i < n)
	{
		printf("i :  %d\n", i);
		map_to_tetri_pos(*(table + i), pos_x, pos_y);
		if (put_tetri_on_map(pos_x, pos_y, map, size) == 1)
		{
			i++;
		}
		else
		{
			size++;
			printf("===>resize map: %d\n", size);
			map = alloc_map(map, size);
			i = 0;
		}
	}
	print_map(map, size);
	return (0);
}
