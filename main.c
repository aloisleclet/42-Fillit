/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 09:52:02 by aleclet           #+#    #+#             */
/*   Updated: 2017/03/24 14:22:23 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		n[0];
	char	***table;

	fd = 0;
	n[0] = 0;
	table = NULL;

	if (!ft_is_input(argc))
		return (1);

	//test
	ft_putstr("Let's go !\n");

	printf("ft_size error : %d\n", ft_size(argv[1], n));
	//main

	// generate table from data
	table = ft_alloc_table(table, n[0]);
//	printf("ok 1\n");
	printf("ft_fill_table error : %d\n", ft_fill_table(table, argv[1]));
//	printf("ok 2\n");

	printf("check_all error : %d\n", check_all(table, n[0]));
//	printf("ok 3\n");
//	printf("nb tetri: %d\n", n[0]);
	solve(table, n[0]);

	//test
	return (0);
}















