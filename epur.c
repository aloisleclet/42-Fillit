/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 15:44:33 by aleclet           #+#    #+#             */
/*   Updated: 2017/07/08 16:20:13 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*epur(char *str)
{
	char	*tmp;
	char	*res;			
	int		len;

	len = 0;
	tmp = str;
	while (*tmp)
	{
		if (*tmp != '\n')
			len++;
		tmp++;
	}
	if (!(res = (char *)malloc(len * sizeof(char))))
		return (0);
	tmp = res;
	while (*str)
	{
		if (*str != '\n')
		{
			*tmp = *str;
			tmp++;
		}
		str++;
	}
	return (res);
}
