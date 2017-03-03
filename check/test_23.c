/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_23.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:18:46 by aleclet           #+#    #+#             */
/*   Updated: 2017/03/03 12:24:05 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 2 X 3


// ##
//  #
//  #

int		ft_test_230(int pos_x[4], int pos_y[4])
{
	return ((pos_x[0] == 0 && pos_y[0] == 0) &&
	(pos_x[1] == 1 && pos_y[1] == 0) &&
	(pos_x[2] == 1 && pos_y[2] == 1) &&
	(pos_x[3] == 1 && pos_y[3] == 2));
}

//  #
// ##
//  #

int		ft_test_231(int pos_x[4], int pos_y[4])
{
	return ((pos_x[0] == 1 && pos_y[0] == 0) &&
	(pos_x[1] == 0 && pos_y[1] == 1) &&
	(pos_x[2] == 1 && pos_y[2] == 1) &&
	(pos_x[3] == 1 && pos_y[3] == 2));
}

//  #
//  #
// ##

int		ft_test_232(int pos_x[4], int pos_y[4])
{
	return ((pos_x[0] == 1 && pos_y[0] == 0) &&
	(pos_x[1] == 1 && pos_y[1] == 1) &&
	(pos_x[2] == 0 && pos_y[2] == 2) &&
	(pos_x[3] == 1 && pos_y[3] == 2));
}

// ##
// #
// #

int		ft_test_233(int pos_x[4], int pos_y[4])
{
	return ((pos_x[0] == 0 && pos_y[0] == 0) &&
	(pos_x[1] == 1 && pos_y[1] == 0) &&
	(pos_x[2] == 0 && pos_y[2] == 1) &&
	(pos_x[3] == 0 && pos_y[3] == 2));
}

// #
// ##
// #

int		ft_test_234(int pos_x[4], int pos_y[4])
{
	return ((pos_x[0] == 0 && pos_y[0] == 0) &&
	(pos_x[1] == 0 && pos_y[1] == 1) &&
	(pos_x[2] == 1 && pos_y[2] == 1) &&
	(pos_x[3] == 0 && pos_y[3] == 2));
}
