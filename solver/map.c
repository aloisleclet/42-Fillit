/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 10:39:06 by aleclet           #+#    #+#             */
/*   Updated: 2017/04/14 15:48:44 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_size_map(char *filename, int *n)
{
	int		fd;
	char	buf[1];
	int		y;
	int		x;

	y = 0;
	x = 0;
	fd = ft_open_file(filename);
	*n = 0;
	while (read(fd, buf, 1))
	{
		x++;
		if (x == 5)
		{
			x = 0;
			y++;
		}
	}
	*n = y / 4;
	return (0);
}

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
	ft_putchar('\n'); // to del in prod
}

int id_letter = 16;// to del


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

