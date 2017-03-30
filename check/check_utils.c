/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 09:16:08 by aleclet           #+#    #+#             */
/*   Updated: 2017/03/30 14:25:41 by aleclet          ###   ########.fr       */
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

void		map_to_tetri_pos(char **map, int pos_x[4], int pos_y[4]) //
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
			if (map[j][i] == '#')
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
		res = brute_force(pos_x, pos_y, type);
		i++;
	}
	return (0);
}
