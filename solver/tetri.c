/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 10:38:57 by aleclet           #+#    #+#             */
/*   Updated: 2017/06/01 15:55:33 by aleclet          ###   ########.fr       */
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
	map[table_pos[id][1][0] + y][table_pos[id][0][0] + x] = id + 65;//map[y][x]
	map[table_pos[id][1][1] + y][table_pos[id][0][1] + x] = id + 65;
	map[table_pos[id][1][2] + y][table_pos[id][0][2] + x] = id + 65;
	map[table_pos[id][1][3] + y][table_pos[id][0][3] + x] = id + 65;
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
			if (map[y][x] == id + 65)
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


