/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_32.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:50:32 by aleclet           #+#    #+#             */
/*   Updated: 2017/03/02 12:25:41 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 3 X 2

// ###
// #

int		ft_test_320(int pos_x[4], int_pos_y[4])
{
	return ((pos_x[0] == 0 && pos_y[0] == 0) &&
	(pos_x[1] == 1 && pos_y[1] == 0) &&
	(pos_x[2] == 2 && pos_y[2] == 0) &&
	(pos_x[3] == 0 && pos_y[3] == 1));
}

// ###
//  #

int		ft_test_321(int pos_x[4], int_pos_y[4])
{
	return ((pos_x[0] == 0 && pos_y[0] == 0) &&
	(pos_x[1] == 1 && pos_y[1] == 0) &&
	(pos_x[2] == 2 && pos_y[2] == 0) &&
	(pos_x[3] == 0 && pos_y[3] == 2));
}

// ###
//   #

int		ft_test_322(int pos_x[4], int_pos_y[4])
{
	return ((pos_x[0] == 0 && pos_y[0] == 0) &&
	(pos_x[1] == 1 && pos_y[1] == 0) &&
	(pos_x[2] == 2 && pos_y[2] == 0) &&
	(pos_x[3] == 0 && pos_y[3] == 2));
}

// #
// ###

int		ft_test_323(int pos_x[4], int_pos_y[4])
{
	return ((pos_x[0] == 0 && pos_y[0] == 0) &&
	(pos_x[1] == 0 && pos_y[1] == 1) &&
	(pos_x[2] == 1 && pos_y[2] == 1) &&
	(pos_x[3] == 2 && pos_y[3] == 1));
}

//  #
// ###

int		ft_test_324(int pos_x[4], int_pos_y[4])
{
	return ((pos_x[0] == 1 && pos_y[0] == 0) &&
	(pos_x[1] == 0 && pos_y[1] == 1) &&
	(pos_x[2] == 1 && pos_y[2] == 1) &&
	(pos_x[3] == 2 && pos_y[3] == 1));
}

//   #
// ###

int		ft_test_325(int pos_x[4], int_pos_y[4])
{
	return ((pos_x[0] == 2 && pos_y[0] == 0) &&
	(pos_x[1] == 0 && pos_y[1] == 1) &&
	(pos_x[2] == 1 && pos_y[2] == 1) &&
	(pos_x[3] == 2 && pos_y[3] == 1));
}

//  ##
// ##

int		ft_test_326(int pos_x[4], int_pos_y[4])
{
	return ((pos_x[0] == 1 && pos_y[0] == 0) &&
	(pos_x[1] == 2 && pos_y[1] == 0) &&
	(pos_x[2] == 0 && pos_y[2] == 1) &&
	(pos_x[3] == 1 && pos_y[3] == 1));
}

// ##
//  ##

int		ft_test_327(int pos_x[4], int_pos_y[4])
{
	return ((pos_x[0] == 0 && pos_y[0] == 0) &&
	(pos_x[1] == 1 && pos_y[1] == 0) &&
	(pos_x[2] == 1 && pos_y[2] == 1) &&
	(pos_x[3] == 2 && pos_y[3] == 1));
}


// 2 X 3


// ##
//  #
//  #

int		ft_test_230(int pos_x[4], int_pos_y[4])
{
	return ((pos_x[0] == 0 && pos_y[0] == 0) &&
	(pos_x[1] == 1 && pos_y[1] == 0) &&
	(pos_x[2] == 1 && pos_y[2] == 1) &&
	(pos_x[3] == 1 && pos_y[3] == 2));
}

//  #
// ##
//  #

int		ft_test_231(int pos_x[4], int_pos_y[4])
{
	return ((pos_x[0] == 1 && pos_y[0] == 0) &&
	(pos_x[1] == 0 && pos_y[1] == 1) &&
	(pos_x[2] == 1 && pos_y[2] == 1) &&
	(pos_x[3] == 1 && pos_y[3] == 2));
}

//  #
//  #
// ##

int		ft_test_232(int pos_x[4], int_pos_y[4])
{
	return ((pos_x[0] == 1 && pos_y[0] == 0) &&
	(pos_x[1] == 1 && pos_y[1] == 1) &&
	(pos_x[2] == 0 && pos_y[2] == 2) &&
	(pos_x[3] == 1 && pos_y[3] == 2));
}

// ##
// #
// #

int		ft_test_233(int pos_x[4], int_pos_y[4])
{
	return ((pos_x[0] == 0 && pos_y[0] == 0) &&
	(pos_x[1] == 1 && pos_y[1] == 0) &&
	(pos_x[2] == 0 && pos_y[2] == 1) &&
	(pos_x[3] == 0 && pos_y[3] == 2));
}

// #
// ##
// #

int		ft_test_234(int pos_x[4], int_pos_y[4])
{
	return ((pos_x[0] == 0 && pos_y[0] == 0) &&
	(pos_x[1] == 0 && pos_y[1] == 1) &&
	(pos_x[2] == 1 && pos_y[2] == 1) &&
	(pos_x[3] == 0 && pos_y[3] == 2));
}

// #
// #
// ##

int		ft_test_235(int pos_x[4], int_pos_y[4])
{
	return ((pos_x[0] == 0 && pos_y[0] == 0) &&
	(pos_x[1] == 0 && pos_y[1] == 1) &&
	(pos_x[2] == 0 && pos_y[2] == 2) &&
	(pos_x[3] == 1 && pos_y[3] == 2));
}

//  #
// ##
// #

int		ft_test_236(int pos_x[4], int_pos_y[4])
{
	return ((pos_x[0] == 1 && pos_y[0] == 0) &&
	(pos_x[1] == 0 && pos_y[1] == 1) &&
	(pos_x[2] == 1 && pos_y[2] == 1) &&
	(pos_x[3] == 0 && pos_y[3] == 2));
}

// #
// ##
//  # 

int		ft_test_237(int pos_x[4], int_pos_y[4])
{
	return ((pos_x[0] == 0 && pos_y[0] == 0) &&
	(pos_x[1] == 0 && pos_y[1] == 1) &&
	(pos_x[2] == 1 && pos_y[2] == 1) &&
	(pos_x[3] == 1 && pos_y[3] == 2));
}

