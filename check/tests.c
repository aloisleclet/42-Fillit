/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:05:38 by aleclet           #+#    #+#             */
/*   Updated: 2017/04/04 14:11:59 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//##
//##

int		ft_test_22(int pos_x[4], int pos_y[4])
{
	if ((pos_x[0] == 0 && pos_y[0] == 0) &&
	(pos_x[1] == 1 && pos_y[1] == 0) &&
	(pos_x[2] == 0 && pos_y[2] == 1) &&
	(pos_x[3] == 1 && pos_y[2] == 1))
		return (220);
	return (0);
}

//#
//#
//#
//#

int		ft_test_14(int pos_x[4], int pos_y[4])
{
	if ((pos_x[0] == 0 && pos_y[0] == 0) &&
	(pos_x[1] == 0 && pos_y[1] == 1) &&
	(pos_x[2] == 0 && pos_y[2] == 2) &&
	(pos_x[3] == 0 && pos_y[3] == 3))
		return (140);
	return (0);
}

//####

int		ft_test_41(int pos_x[4], int pos_y[4])
{
	if ((pos_x[0] == 0 && pos_y[0] == 0) &&
	(pos_x[1] == 1 && pos_y[1] == 0) &&
	(pos_x[2] == 2 && pos_y[2] == 0) &&
	(pos_x[3] == 3 && pos_y[2] == 0))
		return (410);
	return (0);
}

int		ft_test_32(int pos_x[4], int pos_y[4])
{
	if (ft_test_320(pos_x, pos_y))
		return (320);	
	else if (ft_test_321(pos_x, pos_y))
		return (321);	
	else if (ft_test_322(pos_x, pos_y))
		return (322);	
	else if (ft_test_323(pos_x, pos_y))
		return (323);	
	else if (ft_test_324(pos_x, pos_y))
		return (324);	
	else if (ft_test_325(pos_x, pos_y))
		return (325);	
	else if (ft_test_326(pos_x, pos_y))
		return (326);	
	else if (ft_test_327(pos_x, pos_y))
		return (327);
	return (0);
}

int		ft_test_23(int pos_x[4], int pos_y[4])
{
	if (ft_test_230(pos_x, pos_y))
		return (230);	
	else if (ft_test_231(pos_x, pos_y))
		return (231);  
	else if (ft_test_232(pos_x, pos_y))
		return (232);  
	else if (ft_test_233(pos_x, pos_y))
		return (233);  
	else if (ft_test_234(pos_x, pos_y))
		return (234);  
	else if (ft_test_235(pos_x, pos_y))
		return (235);  
	else if (ft_test_236(pos_x, pos_y))
		return (236);  
	else if (ft_test_237(pos_x, pos_y))
		return (237);
	return (0);
}

