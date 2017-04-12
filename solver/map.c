/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:39:27 by aleclet           #+#    #+#             */
/*   Updated: 2017/04/12 16:56:24 by aleclet          ###   ########.fr       */
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

int id_letter = 16;// to del

int		place_found(char **map, int pos_x[4], int pos_y[4], int translate_x, int translate_y)
{
	if (map[pos_y[0] + translate_y][pos_x[0] + translate_x] == '.' &&
	map[pos_y[1] + translate_y][pos_x[1] + translate_x] == '.' &&
	map[pos_y[2] + translate_y][pos_x[2] + translate_x] == '.' &&
	map[pos_y[3] + translate_y][pos_x[3] + translate_x] == '.')
	{
		//write on map
		id_letter++;
		map[pos_y[0] + translate_y][pos_x[0] + translate_x] = id_letter + 48;//map[y][x]
		map[pos_y[1] + translate_y][pos_x[1] + translate_x] = id_letter + 48;
		map[pos_y[2] + translate_y][pos_x[2] + translate_x] = id_letter + 48;
		map[pos_y[3] + translate_y][pos_x[3] + translate_x] = id_letter + 48;
		return (1);
	}
	return (0);
}

char	**put_on_map(int	id, int ***table_pos, char **map)
{
	map[table_pos[id][1][0]][table_pos[id][0][0]] = id_letter + 48;//map[y][x]
	map[table_pos[id][1][1]][table_pos[id][0][1]] = id_letter + 48;
	map[table_pos[id][1][2]][table_pos[id][0][2]] = id_letter + 48;
	map[table_pos[id][1][3]][table_pos[id][0][3]] = id_letter + 48;
	print_map(map, 5);
	return (map);
}















