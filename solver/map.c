/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 10:39:06 by aleclet           #+#    #+#             */
/*   Updated: 2017/04/14 13:47:10 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**alloc_map(char **map, int size) //partir de la max size map
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	map = (char**)ft_alloc(sizeof(char**) * (size + 1));
	while (j < size)
	{
		map[j] = (char*)ft_alloc(sizeof(char*) * (size + 1));
		j++;
	}
	j = 0;
	i = 0;
	while (j < size)
	{
		while (i < size)
		{
			map[j][i] = '.';
			i++;	
		}
		i = 0;
		j++;
	}
	return (map);
}

void	free_map(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_free(map[i]);
		i++;
	}
	free(map);
}

void	print_map(char **map, int size)
{
	int		j;
	int		i;

	i = 0;
	j = 0;

	while (j < size)
	{
		while (i < size)
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

int		is_place(char **map, int ***table_pos, int id, int new_pos[2])
{
	int		x;
	int		y;
	
	x = new_pos[0];
	y = new_pos[1];
	if (map[table_pos[id][1][0] + y][table_pos[id][0][0] + x] == '.' &&
	map[table_pos[id][1][1] + y][table_pos[id][0][1] + x] == '.' &&
	map[table_pos[id][1][2] + y][table_pos[id][0][2] + x] == '.' &&
	map[table_pos[id][1][3] + y][table_pos[id][0][3] + x] == '.')
		return (1);
	return (0);
}

int		put_on_map(char **map, int ***table_pos, int id, int new_pos[2], int size)
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

int		remove_on_map(char **map, int size, int id)
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

int		move_on_map(char **map, int size, int ***table_pos, int id, int new_pos[2])
{
	int		x;
	int		y;
	
	x = new_pos[0];
	y = new_pos[1];

	return (remove_on_map(map, size, id) || put_on_map(map, table_pos, id, new_pos, size));
}
