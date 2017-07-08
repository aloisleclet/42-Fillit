/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 11:12:30 by aleclet           #+#    #+#             */
/*   Updated: 2017/07/08 12:03:29 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				main(int ac, char **av)
{
	char		*tet;
	char		*map;

	if (ac != 2)
	{
		ft_putstr("usage : ./fillit source_file\n");
		return (0);
	}
	if (!(tet = get_file(av[1])))
	{
		ft_putstr("error get\n");
		return (0);
	}
/*	if (!check_error(tet))
	{
		ft_putstr("error check\n");
		return (0);
	}
	if (!epur(tet))
	{
		ft_putstr("error epur\n");
		return (0);
	}
	if (!(print_map(fillit(tet))))
	{
		ft_putstr("error fillit\n");
		return (0);
	}*/
	return (1);
}
