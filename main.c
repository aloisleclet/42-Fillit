/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 09:52:02 by aleclet           #+#    #+#             */
/*   Updated: 2017/03/01 13:35:24 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	***table;
	unsigned char	**bin;
	int		size[2];
	int		pos[4][2];

	fd = 0;
	size[0] = 0;
	size[1] = 0;
	table = NULL;
	bin = NULL;

	if (!ft_is_input(argc))
		return (1);

	ft_putstr("Let's go !\n");

	ft_size(argv[1], &size[0]);	
	printf("%d, %d\n", size[0], size[1]);
	
	//bin = ft_file_to_table_bin(argv[1], bin, 10);

	table = ft_alloc_table(table, 10);
	ft_fill_table(table, argv[1]);

	ft_read_pos(table[0], pos);
	ft_check_all(table);
	return (0);
}















