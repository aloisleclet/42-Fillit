/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 09:52:02 by aleclet           #+#    #+#             */
/*   Updated: 2017/02/28 16:39:43 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	***table;
	unsigned char	**bin;
	int		size[2];

	fd = 0;
	size[0] = 0;
	size[1] = 0;
	table = NULL;
	bin = NULL;

	if (!ft_is_input(argc))
		return (1);

	ft_putstr("Let's go !\n");

	ft_size(argv[1], &size[0]);	
	bin = ft_file_to_table_bin(argv[1], bin, 9);
	printf("%d, %d", size[0], size[1]);

	return (0);
}















