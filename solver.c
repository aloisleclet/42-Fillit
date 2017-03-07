/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:12:43 by aleclet           #+#    #+#             */
/*   Updated: 2017/03/07 14:53:30 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		alloc_map(int size, char ***map)
{

}

int		solve(char ***table, char ***map, int n)
{
	int		i;
	int		pos_x[4];
	int		pos_y[4];

	i = 0;
	while (i < n)
	{
		map_to_tetris_pos(table[i], pos_x, pos_y);
	}
}

int		put_tetri_on_map(int pos_x, int pos_y)
{

}


