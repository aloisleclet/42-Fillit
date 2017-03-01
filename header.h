/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 09:52:03 by aleclet           #+#    #+#             */
/*   Updated: 2017/03/01 10:24:47 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

int		ft_open_file(char *filename);
char	***ft_file_to_table(char *filename, int size[]);
int		ft_size(char *filename, int size[]);
char	***ft_alloc_table(char ***table, int n);
void	ft_print_table(char ***table, int n);

void	ft_read_pos(char **tetri, int pos[4][2]);

void	ft_print_tetri_pos(int pos[4][2]);
int		ft_check_all(char ***table);

#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include "standard_utils.c"
#include "check_utils.c"
#include "utils.c"


#endif
