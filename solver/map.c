/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 10:39:06 by aleclet           #+#    #+#             */
/*   Updated: 2017/04/13 12:29:22 by aleclet          ###   ########.fr       */
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
	ft_putchar('\n'); // to del
}

int id_letter = 16;// to del

//int		*get_tetri_pos(int id) // to finish
//{
//	int	pos[2];
//
//	pos[0] = 0; // x
//	pos[1] = 0; // y
//
//	
//
//	return (pos);
//}

int		is_place(char **map, int ***table_pos, int id, int x, int y)
{
	if (map[table_pos[id][1][0] + y][table_pos[id][0][0] + x] == '.' &&
	map[table_pos[id][1][1] + y][table_pos[id][0][1] + x] == '.' &&
	map[table_pos[id][1][2] + y][table_pos[id][0][2] + x] == '.' &&
	map[table_pos[id][1][3] + y][table_pos[id][0][3] + x] == '.')
		return (1);	
	return (0);
}

char	**put_on_map(char **map, int ***table_pos, int id, int x, int y)
{
	if (!is_place(map, table_pos, id, x, y))
		return (map);// or return a signal
	map[table_pos[id][1][0] + y][table_pos[id][0][0] + x] = id_letter + id + 49;//map[y][x]
	map[table_pos[id][1][1] + y][table_pos[id][0][1] + x] = id_letter + id + 49;
	map[table_pos[id][1][2] + y][table_pos[id][0][2] + x] = id_letter + id + 49;
	map[table_pos[id][1][3] + y][table_pos[id][0][3] + x] = id_letter + id + 49;
	return (map);
}

char	**remove_on_map(char **map, int size, int id)
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
			if (map[y][x] == id_letter + id + 49)
			{
				map[y][x] = '.';
				case_deleted++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (map);
}

char	**move_on_map(char **map, int size, int ***table_pos, int id, int x, int y)
{
	int		new_x;
	int		new_y;

	new_x = x;
	new_y = y;
	map = remove_on_map(map, size, id);
	map = put_on_map(map, table_pos, id, new_x, new_y);
	return (map);
}
