/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 09:52:02 by aleclet           #+#    #+#             */
/*   Updated: 2017/06/01 14:44:25 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		fillit(int argc, char *filename)
{
	int		size;
	char	***table_test;

	size = 0;
	table_test = NULL;
	//======================check part================
	if (argc != 2)
		return (1);
	if (check_map(open(filename, O_RDONLY)))
		return (1);
//	printf("input ok\n");
	if (get_size_map(filename, &size))
		return (1);
//	printf("size ok\n");
	table_test = alloc_table_test(table_test, size);
//	printf("alloc table ok\n");
	if (fill_table_test(table_test, filename))
		return (1);
//	printf("fill table ok\n");
	if (check_all(table_test, size))
		return (1);
	printf("check_all ok\n");
	//======================solve part================
	test(table_test);
	//solve(table, size);
//	printf("solve ok\n");
	free_table_test(table_test, size);
	//free_table_pos
	return (0);
}

int		main(int argc, char **argv)
{
	int		error;

	error = fillit(argc, argv[1]);
	if (error)
		ft_putstr("error\n");
	return (0);
}

