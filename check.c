/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 12:20:59 by aleclet           #+#    #+#             */
/*   Updated: 2017/07/08 15:28:37 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int			check_link(char *str)
{
	int				lnk;
	int				i;
	
	lnk = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			if (i > 1 && str[i - 1] == '#')
				lnk++;
			if (i > 5 && str[i - 5] == '#')
				lnk++;
			if (i < 18 && str[i + 1] == '#')
				lnk++;
			if (i < 14 && str[i + 5] == '#')
				lnk++;
		}
		i++;
	}
	if (lnk != 6 && lnk != 8)
		return (0);
	return (1);
}

static int			check_tet(char *str)
{
	int				i;
	int				hash;

	hash = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
			hash++;
		if (((i + 1) % 5 == 0) && str[i] != '\n')
			return (0);
		else if (((i + 1) % 5 != 0) && (str[i] != '.' && str[i] != '#'))
			return (0);
		i++;
	}
	if (hash != 4)
		return (0);
	return (1);
}	

int					check(char *str)
{
	int				i;

	i = 0;
	while (i == 0 || str[i - 1] != '\0')
	{
		ft_putnbr(i);
		if (i == 0 || str[i - 1] == '\n')
		{
			ft_putstr("ok");
			if (!check_tet(&str[i]) && !check_link(&str[i]))
			{
				ft_putstr("out 1");
				return (0);
			}
		}
		else if (str[i - 1] != '\0')
		{
			ft_putstr("out 2");
			return (0);
		}
		if (i == 0 || str[i - 1] != '\0')
			i += 21;
	}
	ft_putstr("out 3");
	return (1);
}
