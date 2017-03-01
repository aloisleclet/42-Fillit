/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:20:36 by aleclet           #+#    #+#             */
/*   Updated: 2017/03/01 14:54:06 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//check correct tetris

void	ft_read_pos(char **tetri, int pos[4][2])
{
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 0;
	i = 0;

	while (y < 4)
	{
		while (x < 4)
		{
			if (tetri[y][x] == '#')
			{
				pos[i][0] = x;
				pos[i][1] = y;
				i++;
			}
			x++;
		}
		x = 0;
		y++;	
	}
}

//check if all case of tetri is in contact with an other

//		if ((pos[0][1] == pos[1][1]) && (pos[2][1] == pos[3][1]) && (pos[0][0] == pos[2][0]) && (pos[1][0] == pos[3][0]))

//####

int		ft_check_a(int pos[4][2])
{
	if ((pos[0][1] == pos[1][1]) && (pos[0][1] == pos[2][1])  && (pos[0][1]== pos[3][1]))
	{
		printf("horizontal bar\n");		
		return (1);
	}
	return (0);
}

//#
//#
//#
//#

int		ft_check_b(int pos[4][2])
{
	if (pos[0][0] == pos[1][0] && pos[0][0] == pos[2][0]  && pos[0][0]== pos[3][0])
		{
			printf("vertical bar\n");
			return (1);
		}
	return (0);
}
//##
//##

int		ft_check_c(int pos[4][2])
{
	if (pos[0][1] == pos[1][1] && pos[2][1] == pos[3][1] && pos[0][0] == pos[2][0] && pos[1][0] == pos[3][0] && (pos[0][0] + 1) == pos[1][0])
	{
		printf("square\n");
		return (1);
	}
	return (0);
}

//##
// ##

int		ft_check_d(int pos[4][2])
{
		if ((pos[0][1] == pos[1][1]) && (pos[2][1] == pos[3][1]) && (pos[0][0] == (pos[2][0] - 1)))
		{
			printf("stair case top left\n");
			return (1);
		}
	return (0);
}

// ##
//##

int		ft_check_e(int pos[4][2])
{
		if ((pos[0][1] == pos[1][1]) && (pos[2][1] == pos[3][1]) && (pos[0][0] == (pos[2][0] + 1)))
		{
			printf("stair case top right\n");
			return (1);
		}
		return (0);
}

// #
//##
//#

int		ft_check_f(int pos[4][2])
{
		if (pos[0][0] == (pos[1][0] + 1) && (pos[1][1] == pos[2][1]) && (pos[1][0] + 1) == pos[2][0] && (pos[3][0] == (pos[0][0] - 1)))
		{
			printf("stair case up right\n");
			return (1);
		}
		return (0);
}

//#
//##
// #

int		ft_check_g(int pos[4][2])
{
		if (pos[0][0] == (pos[1][0] - 1) && (pos[1][1] == pos[2][1]) && (pos[1][0] + 1) == pos[2][0] && (pos[3][0] == (pos[0][0] + 1)))
		{
			printf("stair case up left\n");
			return (1);
		}
		return (0);
}


//##
//#
//#

int		ft_check_h(int pos[4][2])
{
		printf ("%d %d %d %d\n", pos[0][0], pos[1][0], pos[2][0], pos[3][0]);
		printf ("%d %d %d %d\n", pos[0][1], pos[1][1], pos[2][1], pos[3][1]);

		if ((pos[0][0] + 1) == pos[1][0] && pos[2][0] == pos[0][0] && pos[3][0] == pos[0][0])
		{
			printf("pick right\n");
			return (1);
		}
		return (0);
}


//##
// #
// #

int		ft_check_i(int pos[4][2])
{
		if ((pos[0][0] + 1) == pos[1][0] && pos[2][0] == pos[1][0] && pos[3][0] == pos[1][0])
		{
			printf("pick left\n");
			return (1);
		}
		return (0);
}

//###
//#



//check all

int		ft_check_all(char ***table)
{
	int		i;
	int		pos[4][2];

	i = 0;

	while (table[i])
	{
		printf("\ntetri %d ", i);
		ft_read_pos(table[i], pos);
		//checks
		ft_check_a(pos);
		ft_check_b(pos);
		ft_check_c(pos);
		ft_check_d(pos);
		ft_check_e(pos);
		ft_check_f(pos);
		ft_check_g(pos);
		ft_check_h(pos);
		ft_check_i(pos);
		printf("\n");
		ft_print_tetri_pos(pos);
		i++;
	}
	return (1);
}










































































