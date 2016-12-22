/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 09:52:03 by aleclet           #+#    #+#             */
/*   Updated: 2016/12/22 15:10:24 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "utils.c"

int		ft_is_input(int argc);
int		ft_open_file(char *filename);
void	ft_apply_on_file(char *filenmame, int (*f)(int));

#endif
