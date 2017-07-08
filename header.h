/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 11:12:33 by aleclet           #+#    #+#             */
/*   Updated: 2017/07/06 11:58:56 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "utils.c"


void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_fillit(int argc, char **argv);
void	ft_read(char *filename);
