/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_32.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:50:32 by aleclet           #+#    #+#             */
/*   Updated: 2017/03/03 14:19:03 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 3 X 2

// ###
// #

int		ft_test_320(int pos_x[4], int pos_y[4])
{
	return ((pos_x[0] == 0 && pos_y[0] == 0) &&
	(pos_x[1] == 1 && pos_y[1] == 0) &&
	(pos_x[2] == 2 && pos_y[2] == 0) &&
	(pos_x[3] == 0 && pos_y[3] == 1));
}

// ###
//  #

int		ft_test_321(int pos_x[4], int pos_y[4])
{
	return ((pos_x[0] == 0 && pos_y[0] == 0) &&
	(pos_x[1] == 1 && pos_y[1] == 0) &&
	(pos_x[2] == 2 && pos_y[2] == 0) &&
	(pos_x[3] == 1 && pos_y[3] == 1));
}

// ###
//   #

int		ft_test_322(int pos_x[4], int pos_y[4])
{
	return ((pos_x[0] == 0 && pos_y[0] == 0) &&
	(pos_x[1] == 1 && pos_y[1] == 0) &&
	(pos_x[2] == 2 && pos_y[2] == 0) &&
	(pos_x[3] == 0 && pos_y[3] == 2));
}

// #
// ###

int		ft_test_323(int pos_x[4], int pos_y[4])
{
	return ((pos_x[0] == 0 && pos_y[0] == 0) &&
	(pos_x[1] == 0 && pos_y[1] == 1) &&
	(pos_x[2] == 1 && pos_y[2] == 1) &&
	(pos_x[3] == 2 && pos_y[3] == 1));
}

//  #
// ###

int		ft_test_324(int pos_x[4], int pos_y[4])
{
	return ((pos_x[0] == 1 && pos_y[0] == 0) &&
	(pos_x[1] == 0 && pos_y[1] == 1) &&
	(pos_x[2] == 1 && pos_y[2] == 1) &&
	(pos_x[3] == 2 && pos_y[3] == 1));
}
