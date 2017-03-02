/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 09:52:02 by aleclet           #+#    #+#             */
/*   Updated: 2017/03/02 11:23:10 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	***table;
	int		size[2];

	int		pos_x[4];//position of case of the current tetri
	int		pos_y[4];//position of case of the current tetri

	fd = 0;
	size[0] = 0;
	size[1] = 0;
	table = NULL;

	if (!ft_is_input(argc))
		return (1);

	//test
	ft_putstr("Let's go !\n");

	ft_size(argv[1], &size[0]);	
	printf("%d, %d\n", size[0], size[1]);

	//main

	// generate table from data
	table = ft_alloc_table(table, 10);
	ft_fill_table(table, argv[1]);

	//check data

	map_to_tetri_pos(table[0], pos_x, pos_y);

	//test
	printf("1 x: %d y: %d\n", pos_x[0], pos_y[0]);
	printf("2 x: %d y: %d\n", pos_x[1], pos_y[1]);
	printf("3 x: %d y: %d\n", pos_x[2], pos_y[2]);
	printf("4 x: %d y: %d\n", pos_x[3], pos_y[3]);

	printf("type : %d\n", check_type(pos_x, pos_y));	
	printf("type : %d\n", brute_force(pos_x, pos_y, check_type(pos_x, pos_y)));	

	return (0);
}















