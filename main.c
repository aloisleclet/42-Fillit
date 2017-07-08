/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 11:12:30 by aleclet           #+#    #+#             */
/*   Updated: 2017/07/08 16:54:28 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				main(int ac, char **av)
{
	char		*str;

	if (ac != 2)
	{
		ft_putstr("usage : ./fillit source_file\n");
		return (0);
	}
	if (!(str = get_file(av[1])))
	{
		ft_putstr("error get\n");
		return (0);
	}
	if (!check(str))
	{
		ft_putstr("error check\n");
		return (0);
	}
	if (!(str = epur(str)))
	{
		ft_putstr("error epur\n");
		return (0);
	}
	if (!(str = solver(str)))
	{
		ft_putstr("error solver");
		return (0);
	}
	print_map(str);
	return (1);
}
