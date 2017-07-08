/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 11:12:30 by aleclet           #+#    #+#             */
/*   Updated: 2017/07/06 12:54:40 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("usage : ./fillit source_file\n");
		return (0);
	}
	if (!ft_fillit(argc, argv))
		ft_putstr("error\n");

	return (1);
}
