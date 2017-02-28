/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:20:36 by aleclet           #+#    #+#             */
/*   Updated: 2017/02/28 15:17:30 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//check correct tetris

//##
//##

void	ft_putbin(unsigned int n) // to understand
{
	int		i;
	int		res;

	i = 0;
	res = 0;

	printf("\n");
	while (i < 16)
	{
		i++;
		if (n & 1)
		{
			printf("1");
			res ++;
		}
		else
			printf("0");

		n >>= 1;
		if (i % 4 == 0)
			printf("\n");
	}
	printf("\n");
}

int		ft_valid(unsigned int n)
{
	int		i;
	int		res;

	i = 0;
	res = 0;

	while (i < 16)
	{
		i++;
		if (n & 1)
			res++;
		if (res == 4)
			return (1);
		n >>= 1;
	}
	return (0);
}

int		ft_exception(unsigned int tetri)
{
	int		res;
	int		i;
	unsigned int ex[7];

	res = 0;
	i = 0;
	ex[0] = 0b0000000110011000;
	ex[1] = 0b0001100110000000;
	ex[2] = 0b0011100100000000;
	ex[3] = 0b0001110010000000;
	ex[4] = 0b0000001110010000;
	ex[5] = 0b0000000111001000;
	ex[6] = 0b0000000000111001;

	while (i < 7)
	{
		while (tetri == ex[i])
		{
			res++;
			if (res == 16)
				return (1);
		}
		res = 0;
		i++;	
	}	
	return (0);
}

// ####

int		ft_check_a()
{
	int				res;
	unsigned int 	bar;

	res = 0;
	bar	= 0b0001000100010001; //vertical
	while (ft_valid(bar))
	{
		ft_putbin(bar);
		bar = bar << 1;
	}
	bar = 0b0000000000001111; // horizontal
	while (ft_valid(bar))
	{
		ft_putbin(bar);
		bar = bar << 4;
	}
	return (res);
}

// ##
// ##

int		ft_check_b()
{
	int				res;
	unsigned int 	square;
   
	res = 0;
	square = 0b0000000000110011;
	while (ft_valid(square))
	{
		if (!(ft_exception(square)))
			ft_putbin(square);	
		square = square << 1;
	}
	return (res);
}

//  #
// ###

int		ft_check_c()
{
	int				res;
	unsigned int 	piece;
   
	res = 0;
	piece = 0b0000000000100111;
	while (ft_valid(piece))
	{
		if (!(ft_exception(piece)))
			ft_putbin(piece);	
		piece = piece << 1;
	}
	return (res);
}

int		ft_check_all_tetris(unsigned char **bin)
{
	int		n;

	n = 0;

	while (bin[n])
	{
		ft_check_a();
		ft_check_b();
		ft_check_c();
		n++;
	}
	

	return (1);
}
