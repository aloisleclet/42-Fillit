/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 09:52:02 by aleclet           #+#    #+#             */
/*   Updated: 2017/03/02 13:37:15 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	***table;
	int		size[2];

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

	check_all(table);
	//test
	

	return (0);
}















