/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 09:52:03 by aleclet           #+#    #+#             */
/*   Updated: 2017/03/24 14:23:14 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

//standard_utils

int		ft_open_file(char *filename);

//utils

int		ft_size(char *filename, int n[0]);
char	***ft_alloc_table(char ***table, int n);
void	ft_print_table(char ***table, int n);
void	ft_print_tetri_pos(int pos[4][2]);

//tests

int		ft_test_22(int pos_x[4], int pos_y[4]);
int		ft_test_14(int pos_x[4], int pos_y[4]);
int		ft_test_41(int pos_x[4], int pos_y[4]);

int		ft_test_32(int pos_x[4], int pos_y[4]);

int		ft_test320(int pos_x[4], int pos_y[4]);
int		ft_test321(int pos_x[4], int pos_y[4]);
int		ft_test322(int pos_x[4], int pos_y[4]);
int		ft_test323(int pos_x[4], int pos_y[4]);
int		ft_test324(int pos_x[4], int pos_y[4]);
int		ft_test325(int pos_x[4], int pos_y[4]);
int		ft_test326(int pos_x[4], int pos_y[4]);
int		ft_test327(int pos_x[4], int pos_y[4]);

int		ft_test_23(int pos_x[4], int pos_y[4]);

int		ft_test230(int pos_x[4], int pos_y[4]);
int		ft_test231(int pos_x[4], int pos_y[4]);
int		ft_test232(int pos_x[4], int pos_y[4]);
int		ft_test233(int pos_x[4], int pos_y[4]);
int		ft_test234(int pos_x[4], int pos_y[4]);
int		ft_test235(int pos_x[4], int pos_y[4]);
int		ft_test236(int pos_x[4], int pos_y[4]);
int		ft_test237(int pos_x[4], int pos_y[4]);

//check_utils

void	map_to_tetri_pos(char **map, int pos_x[4], int pos_y[4]);
int		check_type(int pos_x[4], int pos_y[4]);
int		brute_force(int pos_x[4], int pos_y[4], int type);
int		check_all(char ***table, int n);

//solver

int		solve(char ***table, int n);

#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include "check/test_32.c"
#include "check/test_32_afterpart.c"

#include "check/test_23.c"
#include "check/test_23_afterpart.c"

#include "check/tests.c"

#include "standard_utils.c"
#include "check/check_utils.c"
#include "utils.c"

#include "solver.c"

#endif
