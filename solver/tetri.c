/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 10:38:57 by aleclet           #+#    #+#             */
/*   Updated: 2017/04/14 14:02:52 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		translation(int pos_x[4], int pos_y[4])
{
	int		n;
	int		origin_x;
	int		origin_y;

	n = 0;
	origin_x = 4;
	origin_y = pos_y[0];	
	while (n < 4)
	{
		origin_x = (pos_x[n] < origin_x) ? pos_x[n] : origin_x;
		n++;
	}

	n = 0;
	while (n < 4)
	{
		pos_x[n] -= origin_x;
		pos_y[n] -= origin_y;
		n++;
	}
}

void		table_test_to_tetri_pos(char **table_test, int pos_x[4], int pos_y[4]) //
{
	int		i;
	int		j;
	int		n;

	i = 0;
	j = 0;
	n = 0;
	while (j < 4)
	{
		while (i < 4)
		{
			if (table_test[j][i] == '#')
			{
				pos_x[n] = i;
				pos_y[n] = j;
				n++;
			}
			i++;
		}
		i = 0;
		j++;
	}
	translation(pos_x, pos_y);
}

int		t_too_big(int pos_x[4], int pos_y[4], int size) // for doing what ?
{
	int		type;
	int		tetri_size = 0;

	type = check_type(pos_x, pos_y);
	if (type == 22)
		tetri_size = 2;
	if (type == 23 || type == 32)
		tetri_size = 3;
	if (type == 14 || type == 41)
		tetri_size = 4;
	return (tetri_size > size);
}

int		tetri_exceed_map(int ***table_pos, int id, int x, int y, int size)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if ((table_pos[id][0][i] + x) >= size)
			return (1); //limit x
		else if ((table_pos[id][1][i] + y) >= size)
			return (2); //limit y
		i++;
	}
	return (0);
}

//===================================table pos utils

int		***alloc_table_pos(int nb)
{
	int		***table_pos;

	table_pos = ft_alloc(sizeof(int***) * nb + 1);
	while ((nb--))
	{
		table_pos[nb] = ft_alloc(sizeof(int**) * 2 + 1);
		table_pos[nb][0] = ft_alloc(sizeof(int*) * 4 + 1);
		table_pos[nb][1] = ft_alloc(sizeof(int*) * 4 + 1);
	}
	return (table_pos);
}

int		***fill_table_pos(char ***table_test, int ***table_pos, int nb)
{
	int		i;
	int		pos_x[4];
	int		pos_y[4];

	i = 0;
	while ((nb--))
	{
		table_test_to_tetri_pos(table_test[nb], pos_x, pos_y);
		i = 0;
		while (i < 4)
		{
			table_pos[nb][0][i] = pos_x[i];
			table_pos[nb][1][i] = pos_y[i];
			i++;
		}
	}
	return (table_pos);
}

//int		put_tetri_on_map(int pos_x[4], int pos_y[4], char **map, int size_map)
//{
//	int		translate_x;
//	int		translate_y;
//
//	translate_x = 0;
//	translate_y = 0;
//	if (t_too_big(pos_x, pos_y, size_map))
//		return (0);
//	while (translate_y < size_map && !place_found(map, pos_x, pos_y, translate_x, translate_y))
//	{
//		if (tetri_exceed_map(pos_x, pos_y, translate_x, translate_y, size_map) == 0)//x
//		{
//			translate_x = -1;//
//			translate_y++;
//		}
//		if (tetri_exceed_map(pos_x, pos_y, translate_x, translate_y, size_map) == -1)//y
//		{
//			return (0);
//		}
//		else
//		{
//			translate_x++;
//		}
//	}
//	return (1);
//}
//
//void	solve(char ***table, int n)
//{
//	int		i;
//	int		size;
//	int		pos_x[4];
//	int		pos_y[4];
//	char	**map;
//
//	size = 2;
//	i = 0;
//	map = NULL;
//	map = alloc_map(map, size);
//	while (i < n)
//	{
//		map_to_tetri_pos(*(table + i), pos_x, pos_y);
//		if (put_tetri_on_map(pos_x, pos_y, map, size) == 1)
//		{
//			i++;
//		}
//		else
//		{
//			size++;
//			id = 16;//reset A
//			map = alloc_map(map, size);//leaks
//			i = 0;
//		}
//	}
//	print_map(map, size);
//	free_map(map, size);
//}

void	test(char ***table_test)
{
	int		***table_pos;
	int		size;
	char	**map;
	int		new_pos[2];	
	int		init_pos[2];	

	init_pos[0] = 0;
	init_pos[1] = 0;
	new_pos[0] = 2;
	new_pos[1] = 2;
	size = 5;
	//map init
	map = NULL;
	map = alloc_map(map, size);
	//table_pos init
	table_pos = alloc_table_pos(size);
	table_pos = fill_table_pos(table_test, table_pos, size);
	//actions
	put_on_map(map, table_pos, 3, init_pos, size);
	print_map(map, size);//display
	remove_on_map(map, size, 3);
	print_map(map, size);//display
	move_on_map(map, size, table_pos, 3, new_pos);
	print_map(map, size);//display
}

int		ft_fillit(int argc, char *filename)
{
	int		size;
	char	***table_test;

	size = 0;
	table_test = NULL;
	//======================check part================
	if (argc != 2)
		return (1);
	if (ft_check_map(open(filename, O_RDONLY)))
		return (1);
//	printf("input ok\n");
	if (ft_size(filename, &size))
		return (1);
//	printf("size ok\n");
	table_test = ft_alloc_table(table_test, size);
//	printf("alloc table ok\n");
	if (ft_fill_table(table_test, filename))
		return (1);
//	printf("fill table ok\n");
	if (check_all(table_test, size))
		return (1);
	printf("check_all ok\n");
	//======================solve part================
	test(table_test);
	//solve(table, size);
//	printf("solve ok\n");
	ft_free_table(table_test, size);
	return (0);
}
