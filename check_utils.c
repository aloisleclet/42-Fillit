/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:20:36 by aleclet           #+#    #+#             */
/*   Updated: 2017/02/28 16:59:05 by aleclet          ###   ########.fr       */
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
			x++;
			if (tetri[y][x] == '#')
			{
				pos[i][0] = x;
				pos[i][1] = y;
				i++;
			}
		}
		x = 0;
		y++;	
	}
}

//check if all case of tetri is in contact with an other

int		ft_check_a(int pos[4][2])
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;

	while (i < 4)
	{
		x = pos[i][0];
		y = pos[i][1];
		//condition
		i++;	
	}


}
