/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 09:52:11 by aleclet           #+#    #+#             */
/*   Updated: 2017/03/31 16:51:08 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	***ft_alloc_table(char ***table, int n)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!(table = (char***)ft_alloc(sizeof(char**) * (n + 1))))
		return (NULL);
	while ((n--))
	{
			table[n] = (char **)ft_alloc(sizeof(char**) * 5);
		while (y < 4)
		{
			table[n][y] = (char *)ft_alloc(sizeof(char*) * 5);
			x = 0;
			y++;
		}
		y = 0;
	}
	return (table);
}

void	ft_free_table(char ***table, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_free(table[i]);
		i++;
	}
	free(table);
}

void	ft_manage_xyi(int *i, int *y, int *x, char c)
{
	if (c != '\n')
	{
		*x += 1;
	}
	if (c == '\n')
	{
		*x = 0;
		*y += 1;
		if (*y == 5)
		{
			*y = 0;
			*i += 1;
		}
		//why when you replace by a ternaire expression it segfault ?
	}
}

int		ft_fill_table(char ***table, char *filename)
{
	int		fd;
	int		x;
	int		y;
	int		i;
	char	buf[1];

	x = 0;
	y = 0;
	i = 0;
	fd = ft_open_file(filename);
	while (read(fd, buf, 1))
	{
		if (buf[0] != '\n')
		{
			table[i][y][x] = buf[0];
		}
		ft_manage_xyi(&i, &y, &x, buf[0]);
	}
	return (table == NULL);
}

int		ft_check_engine(char c, int *x, int *y, int *nb_case)
{ 
	int 	m;

	m = 0;
	*x += 1;
	printf("%c", c);
	if (c == '\n' && ((*x == 5) || ((*x == 1) && (*y % 5) == 0)))
	{
		printf("1\n");
	}
	else if (c == '.' && (*x != 5) && (*y % 5) != 0)
	{
		printf("2\n");
	}
	else if (c == '#' && (*x != 5) && ((*y % 5) != 0))
	{
		*nb_case += 1;
		printf("3\n");
		printf("case %d\n", *nb_case);
	}
	else
	{
		printf("error buf[0]: [%c], x: %d, y: %d\n", c, *x, *y);
		return (1);
	}
	if (*x == 5 || (*x == 1 && c == '\n') || *y == 4) //end of line or end of tetri
	{
		if (*x == 1) //end of tetri
		{
			if (*nb_case != 4)
				return (1);
			*nb_case = (*nb_case == 4) ? 0 : *nb_case;
		}
		*x = 0;
		*y += 1;
	}
	m = (*x) * (*y);
	//printf("tot: %d\n", m);
	return (0);
}

int		ft_check_map(int fd)
{
	int		i;
	int		buf[1];
	int		x;
	int		y;
	int		nb_case;

	x = 0;
	y = 1;
	nb_case = 0;
	i = 0;
	while (read(fd, buf, 1))
	{ 
		i++;
		if (ft_check_engine(buf[0], &x, &y, &nb_case))
		{
	//		printf(" error\n");
			return (1);
		}
	}
	return ((x != 1) && (y % 5) && (!(((y % 5) == 0) || y == 4)));
}

int		ft_size(char *filename, int *n)
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

//int		ft_size(char *filename, int n[0])
//{
//	int		fd;
//	char	buf[1];
//	int		y;
//	int		x;
//
//	y = 0;
//	x = 0;
//	fd = ft_open_file(filename);
//	n[0] = 0;
//	while (read(fd, buf, 1))
//	{
//		x++;
//		if (((x == 6 && (y % 5)) || (x == 0 && !(y % 5))) && y != 0 && buf[0] != '\n')
//			return (1);
//		if (x == 5)
//		{
//			x = 0;
//			y++;
//		}
//	}
//	n[0] = y / 4;
//	return (0);
//}
