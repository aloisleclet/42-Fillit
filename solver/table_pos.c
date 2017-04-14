/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:28:44 by aleclet           #+#    #+#             */
/*   Updated: 2017/04/14 16:15:29 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//we transform table_test in table_pos to manipulate tetri in the solver part
//
//n -> 0 - 25 represent id of tetri
//xy -> 0 = x / 1 = y
//i -> 0 - 3 represent the id of one case of tetri
//exemple :
//
//table_pos[1][0][2] = 0; //third case of second tetri is on the first x line 

void		minifie_tetri(int pos_x[4], int pos_y[4])
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

void		table_test_to_tetri_pos(char **table_test, int pos_x[4], int pos_y[4])
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
			if (table_test[j][i] == '#')
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
	minifie_tetri(pos_x, pos_y);
}

int		***alloc_table_pos(int nb)
{
	int		***table_pos;

	table_pos = ft_alloc(sizeof(int***) * nb + 1);
	while ((nb--))
	{
		table_pos[nb] = ft_alloc(sizeof(int**) * 2 + 1);
		table_pos[nb][0] = ft_alloc(sizeof(int*) * 4 + 1);
		table_pos[nb][1] = ft_alloc(sizeof(int*) * 4 + 1);
	}
	return (table_pos);
}

int		***fill_table_pos(char ***table_test, int ***table_pos, int n)
{
	int		i;
	int		pos_x[4];
	int		pos_y[4];

	i = 0;
	while ((n--))
	{
		table_test_to_tetri_pos(table_test[n], pos_x, pos_y);
		i = 0;
		while (i < 4)
		{
			table_pos[n][0][i] = pos_x[i];
			table_pos[n][1][i] = pos_y[i];
			i++;
		}
	}
	return (table_pos);
}

//todo : free table pos

