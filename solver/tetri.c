/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 10:38:57 by aleclet           #+#    #+#             */
/*   Updated: 2017/04/14 15:51:00 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*get_tetri_pos(int id, char **map, int size, int new_pos[2])
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	new_pos[0] = 0; // x
	new_pos[1] = 0; // y
	
	while (y < size)
	{
		while (x < size)
		{
			if (map[y][x] == id + 45)
			{
				new_pos[0] = x;
				new_pos[1] = y;
			}
		}
		x = 0;
		y++;
	}
	return (new_pos);
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

int		add_tetri(char **map, int ***table_pos, int id, int new_pos[2], int size)
{
	int		limit_exceed;
	int		x;
	int		y;
	
	x = new_pos[0];
	y = new_pos[1];
   	limit_exceed = tetri_exceed_map(table_pos, id, x, y, size);

	if ((limit_exceed != 0) || !is_place(map, table_pos, id, new_pos))
		return (limit_exceed);
	map[table_pos[id][1][0] + y][table_pos[id][0][0] + x] = id + 45;//map[y][x]
	map[table_pos[id][1][1] + y][table_pos[id][0][1] + x] = id + 45;
	map[table_pos[id][1][2] + y][table_pos[id][0][2] + x] = id + 45;
	map[table_pos[id][1][3] + y][table_pos[id][0][3] + x] = id + 45;
	return (0);
	//map[table_pos[id][1][0] + y][table_pos[id][0][0] + x] = id_letter + id + 49;//map[y][x]
}

int		del_tetri(char **map, int size, int id)
{
	int		x;
	int		y;
	int		case_deleted;

	x = 0;
	y = 0;
	case_deleted = 0;
	while (y < size && case_deleted < 4)
	{
		while (x < size && case_deleted < 4)
		{
			if (map[y][x] == id + 45)
			{
				map[y][x] = '.';
				case_deleted++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int		move_tetri(char **map, int size, int ***table_pos, int id, int new_pos[2])
{
	int		x;
	int		y;
	
	x = new_pos[0];
	y = new_pos[1];

	return (del_tetri(map, size, id) || add_tetri(map, table_pos, id, new_pos, size));
}




//================================================================================

//int		t_too_big(int pos_x[4], int pos_y[4], int size)
//{
//	int		type;
//	int		tetri_size = 0;
//
//	type = check_type(pos_x, pos_y);
//	if (type == 22)
//		tetri_size = 2;
//	if (type == 23 || type == 32)
//		tetri_size = 3;
//	if (type == 14 || type == 41)
//		tetri_size = 4;
//	return (tetri_size > size);
//}
//
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
	add_tetri(map, table_pos, 3, init_pos, size);
	print_map(map, size);//display
	del_tetri(map, size, 3);
	print_map(map, size);//display
	move_tetri(map, size, table_pos, 3, new_pos);
	print_map(map, size);//display
}

int		fillit(int argc, char *filename)
{
	int		size;
	char	***table_test;

	size = 0;
	table_test = NULL;
	//======================check part================
	if (argc != 2)
		return (1);
	if (check_map(open(filename, O_RDONLY)))
		return (1);
//	printf("input ok\n");
	if (get_size_map(filename, &size))
		return (1);
//	printf("size ok\n");
	table_test = alloc_table_test(table_test, size);
//	printf("alloc table ok\n");
	if (fill_table_test(table_test, filename))
		return (1);
//	printf("fill table ok\n");
	if (check_all(table_test, size))
		return (1);
	printf("check_all ok\n");
	//======================solve part================
	test(table_test);
	//solve(table, size);
//	printf("solve ok\n");
	free_table_test(table_test, size);
	return (0);
}
