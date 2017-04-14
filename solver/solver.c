/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:19:15 by aleclet           #+#    #+#             */
/*   Updated: 2017/04/14 16:20:24 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




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

