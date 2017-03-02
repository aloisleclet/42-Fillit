/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 09:52:03 by aleclet           #+#    #+#             */
/*   Updated: 2017/03/02 11:50:14 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

//standard_utils

int		ft_open_file(char *filename);

//utils

char	***ft_file_to_table(char *filename, int size[]);
int		ft_size(char *filename, int size[]); // todo fix some error
char	***ft_alloc_table(char ***table, int n);
void	ft_print_table(char ***table, int n);
void	ft_print_tetri_pos(int pos[4][2]);

//tests

int		ft_test_22(int pos_x[4], int pos_y[4]);
int		ft_test_14(int pos_x[4], int pos_y[4]);
int		ft_test_41(int pos_x[4], int pos_y[4]);
int		ft_test_32(int pos_x[4], int pos_y[4]);
//int		ft_test_23(int pos_x[4], int pos_y[4]);

//check_utils

void	map_to_tetri_pos(char **map, int pos_x[4], int pos_y[4]);
int		check_type(int pos_x[4], int pos_y[4]);
int		brute_force(int pos_x[4], int pos_y[4], int type);

#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include "tests.c"
#include "test_32.c"

#include "standard_utils.c"
#include "check_utils.c"
#include "utils.c"


#endif
