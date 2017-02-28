/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 09:52:03 by aleclet           #+#    #+#             */
/*   Updated: 2017/02/28 16:39:17 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include "standard_utils.c"
#include "check_utils.c"
#include "utils.c"

int		ft_open_file(char *filename);
char	***ft_file_to_table(char *filename, int size[]);
int		ft_size(char *filename, int size[]);
char	***ft_alloc_table(char ***table, int x);
void	ft_print_table(char ***table, int n);

#endif
