/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 09:52:02 by aleclet           #+#    #+#             */
/*   Updated: 2017/03/27 15:20:55 by aleclet          ###   ########.fr       */
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

	//main test
	
	printf("ft_size error : %d\n", ft_size(argv[1], n));
	table = ft_alloc_table(table, n[0]);
	printf("ft_fill_table error : %d\n", ft_fill_table(table, argv[1]));

	printf("check_all error : %d\n", check_all(table, n[0]));
//	if (!check_all(table, n[0])
//	else
//		put_str("erro");
	solve(table, n[0]);
	ft_free_table(table, n[0]);
	return (0);
}

