/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:38:56 by aleclet           #+#    #+#             */
/*   Updated: 2017/03/27 15:20:45 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s++)
		ft_putchar(*(s - 1));
}

int		ft_is_input(int argc)
{
	if (argc == 2)
		return (1);
	return (0);
}

int		ft_open_file(char *filename)
{
	int		fd;	

	fd = open(filename, O_RDONLY);
	if (fd != -1)
		return (fd);	
	else
		return (0);	
}

void	*ft_alloc(int size)
{
	void *p;

	p = malloc(size);

	if (!p)
		return (0);
	return (p);
}

void	ft_free(void *p)
{
	if (p)
		free(p);
}
