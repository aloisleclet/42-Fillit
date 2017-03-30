/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:12:43 by aleclet           #+#    #+#             */
/*   Updated: 2017/03/30 15:50:45 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**alloc_map(char **map, int n) //partir de la max size map
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	map = (char**)ft_alloc(sizeof(char**) * (n + 1));
	while (j < n)
	{
		map[j] = (char*)ft_alloc(sizeof(char*) * (n + 1));
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

void	free_map(char **map, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_free(map[i]);
		i++;
	}
	free(map);
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
			ft_putchar(map[j][i]);
			i++;
		}
		i = 0;	
		j++;
		ft_putchar('\n');
	}
}

int		limit_map(int pos_x[4], int pos_y[4], int translate_x, int translate_y, int size_map)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if ((pos_x[i] + translate_x) >= size_map)
		{
			return (0); //limit x
		}
		else if ((pos_y[i] + translate_y) >= size_map)
		{
			return (-1); //limit y
		}
		i++;
	}
	return (1);
}

int id = 16;// to del

int		place_found(char **map, int pos_x[4], int pos_y[4], int translate_x, int translate_y)
{
	if (map[pos_y[0] + translate_y][pos_x[0] + translate_x] == '.' &&
	map[pos_y[1] + translate_y][pos_x[1] + translate_x] == '.' &&
	map[pos_y[2] + translate_y][pos_x[2] + translate_x] == '.' &&
	map[pos_y[3] + translate_y][pos_x[3] + translate_x] == '.')
	{
		id++;
		//id = (id > 26) ? 16 : id + 1;//to del
		map[pos_y[0] + translate_y][pos_x[0] + translate_x] = id + 48;//map[y][x]
		map[pos_y[1] + translate_y][pos_x[1] + translate_x] = id + 48;
		map[pos_y[2] + translate_y][pos_x[2] + translate_x] = id + 48;
		map[pos_y[3] + translate_y][pos_x[3] + translate_x] = id + 48;
		return (1);
	}
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
		if (limit_map(pos_x, pos_y, translate_x, translate_y, size_map) == 0)//x
		{
			translate_x = -1;//
			translate_y++;
		}
		if (limit_map(pos_x, pos_y, translate_x, translate_y, size_map) == -1)//y
		{
			return (0);
		}	
		else
			translate_x++;
	}
	//print_map(map, size_map);
	return (1);
}

int		init_map_size(char ***table, int n) // to recode
{
	int		size;
	int		i;
	int		pos_x[4];
	int		pos_y[4];
	int		is_not_a_square;

	size = 0;
	i = 0;
	is_not_a_square = 0;
	if (n == 1)
	{
		map_to_tetri_pos(*(table + 0), pos_x, pos_y);
		while (i < 4)
		{
			if (pos_x[i] > 2 && pos_y[i] > 2)
				is_not_a_square++;
			i++;
		}
		size = (!is_not_a_square) ? 2 : 3; // error 4
	}
	else
		size = 3;
	return (size);
}

void	solve(char ***table, int n)
{
	int		i;
	int		size;
	int		pos_x[4];
	int		pos_y[4];
	char	**map;

	size = init_map_size(table, n);
	i = 0;
	map = NULL;
	map = alloc_map(map, size);
	while (i < n)
	{
		map_to_tetri_pos(*(table + i), pos_x, pos_y);
		if (put_tetri_on_map(pos_x, pos_y, map, size) == 1)
			i++;
		else
		{
			size++;
			//free_map(map, size);
			id = 16;//reset A
			map = alloc_map(map, size);//leaks
			i = 0;
		}
	}
	print_map(map, size);
	free_map(map, size);
}

int		ft_fillit(int argc, char *filename)
{
	int		fd;
	int		n;
	char	***table;

	fd = 0;
	n = 0;
	table = NULL;
	if (!ft_is_input(argc))
		return (1);
	if (ft_check_map(filename))
		return (1);
	printf("input ok\n");
	if (ft_size(filename, &n))
		return (1);
	printf("size ok\n");
	table = ft_alloc_table(table, n);
	printf("alloc table ok\n");
	if (ft_fill_table(table, filename))
		return (1);
	printf("fill table ok\n");
	if (check_all(table, n))
		return (1);
	printf("check_all ok\n");
	solve(table, n);
	ft_free_table(table, n);
	return (0);
}
