/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 09:16:08 by aleclet           #+#    #+#             */
/*   Updated: 2017/04/11 16:38:12 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//int		ft_check_engine(char c, int *x, int *y, int *nb_case)
//{ 
//	int 	m;
//
//	m = 0;
//	*x += 1;
//	printf("%c", c);
//	if (c == '\n' && ((*x == 5) || ((*x == 1) && (*y % 5) == 0)))
//	{
//	//	printf("1\n");
//	}
//	else if (c == '.' && (*x != 5) && (*y % 5) != 0)
//	{
//	//	printf("2\n");
//	}
//	else if (c == '#' && (*x != 5) && ((*y % 5) != 0))
//	{
//		*nb_case += 1;
//	//	printf("3\n");
//	//	printf("case %d\n", *nb_case);
//	}
//	else
//	{
//	//	printf("error buf[0]: [%c], x: %d, y: %d\n", c, *x, *y);
//		return (1);
//	}
//	if (*x == 5 || (*x == 1 && c == '\n') || *y == 4) //end of line or end of tetri
//	{
//		if (*x == 1) //end of tetri
//		{
//			if (*nb_case != 4)
//				return (1);
//			*nb_case = (*nb_case == 4) ? 0 : *nb_case;
//		}
//		*x = 0;
//		*y += 1;
//	}
//	m = (*x) * (*y);
//	//printf("tot: %d\n", m);
//	return (0);
//}

int		ft_check_engine(char **str)
{
	int		i;
	int		nb_case;
	char c;

	i = 1;
	c = 'a';
	nb_case = 0;
	while (i < 20)
	{
		c = *(*str + i);
		if (((i % 5) == 0 && c != '\n') || ((i % 5) != 0 && c != '.' && c != '#'))
			return (0);
		if (c == '#')
			nb_case += 1;
		i++;
	}
	return (nb_case == 4);
}

int		ft_check_map(int fd)
{
	char	buf[1];
	int		i;
	int		nbt;
	char	*s;

	i = 0;
	nbt = 0;
	s = malloc(21);

	while (read(fd, buf, 1))
	{ 
		i++;
		s[i] = buf[0];
//		printf("%c", buf[0]);
		if (i == 20)
		{
			if (!ft_check_engine(&s))
				return (1);
			nbt++;
		}
		if (i == 21 && s[i] != '\n')
			return (1);
		else if (i == 21 && s[i] == '\n')
			i = 0;
	}
//	printf("[%c] %d\n", s[i], i);
	return ((s[i] == '\n' && i == 21) || !(i == 20 || i == 21));
}

int		ft_size(char *filename, int *n) // to do what ?
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

int		check_type(int pos_x[4], int pos_y[4])
{
	int		i;
	int		max_x;
	int		max_y;

	max_x = 0;
	max_y = 0;
	i = 4;
	while (i--)
	{
		max_x = (pos_x[i] > max_x) ? pos_x[i] : max_x;
		max_y = (pos_y[i] > max_y) ? pos_y[i] : max_y;
	}
	max_x++;
	max_y++;
	if (max_x == 2 && max_y == 2)
		return (22);
	else if (max_x == 1 && max_y == 4)
		return (14);
	else if (max_x == 4 && max_y == 1)
		return (41);
	else if (max_x == 3 && max_y == 2)
		return (32);
	else if (max_x == 2 && max_y == 3)
		return (23);
	return (0);
}

int		brute_force(int pos_x[4], int pos_y[4], int type)
{
	int		res;

	res = 0;
	if (type == 22)
		res = ft_test_22(pos_x, pos_y);
	else if (type == 14)
		res = ft_test_14(pos_x, pos_y);
	else if (type == 41)
		res = ft_test_41(pos_x, pos_y);
	else if (type == 32)
		res = ft_test_32(pos_x, pos_y);
	else if (type == 23)
		res = ft_test_23(pos_x, pos_y);
	return (res);	
}

int		check_all(char ***table, int n)
{
	int		pos_x[4];	
	int		pos_y[4];	
	int		i;
	int		type;
	int		res;

	type = 0;
	i = 0;
	res = 0;
	while (i < n)
	{
		map_to_tetri_pos(table[i], pos_x, pos_y);
		type = check_type(pos_x, pos_y);
		if (!type)
			return (1);
		res = brute_force(pos_x, pos_y, type);
		i++;
	}
	return (0);
}
