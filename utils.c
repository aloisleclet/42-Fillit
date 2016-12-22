/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 09:52:11 by aleclet           #+#    #+#             */
/*   Updated: 2016/12/22 15:14:28 by aleclet          ###   ########.fr       */
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
/////////////////////////////TABLE UTILS
void	ft_apply_on_file(char *filename, int (*f)(int))
{
	int	fd;

	fd = 0;
	fd = ft_open_file(filename);
	f(fd);
	close(fd);
}

void	ft_print_table(char **table, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < y)
	{
		while (i < x)
		{
			ft_putchar(*(*(table + j) + i));
			i++;	
		}
		j++;
		i = 0;	
	}
}

char	**ft_alloc_table(int x, int y)
{
	char	**table;
	int		i;

	i = 0;
	table = NULL;
	if (!(table = (char**)malloc(sizeof(char*) * (y + 1))))
		return (NULL);
	while (i < y)
	{
		if (!(*(table + i) = (char*)malloc(sizeof(char) * (x + 1))))
			return (NULL);
		i++;
	}
	return (table);
}

char	**ft_fill_table(char **table, char *filename) // if the file is not valid risk of segfault ...
{
	int		y;
	int		x;
	int		n;
	char	*buf;
	int		fd;

	buf = malloc(1);
	fd = ft_open_file(filename);
	n = 0;
	y = 0;
	x = 0;
	while ((n = read(fd, buf, 1)))
	{
		if (buf[0] == '\n')
		{
			y++;
			x = 0;
		}
		*(*(table + y) + x) = *buf;
		x++;
	}
	close (fd);
	return (table);
}

char	**ft_file_to_table(char *filename)
{
	int		fd;
	char	buf[1];
	int		x;
	int		y;
	char	**res;

	x = 0;
	y = 0;
	res = NULL;
	fd = ft_open_file(filename);
	while (read(fd, buf, 1) && buf[0] != '\n')
	{
		if (buf[0] == '\n')
		{
			y++;
		}
		y = 4;
		x++;
	}
	close(fd);
	res = ft_alloc_table(x, y);
	ft_fill_table(res, filename);
	ft_print_table(res, x, y);
	return (res);
}


/////////////////////////////CHECK UTILS

int		ft_is_valid(char **table, int x, int y)
{


	return (1);
}

int		ft_check_nb_tetri(int fd) // to recode
{
	size_t n;
	char	buf[1];
	int		x;
	int		y;

	n = 0;
	x = 0;
	y = 0;
	while ((n = read(fd, buf, 1)))
	{
		if (buf[0] == '\n')
			y++;
		else if (buf[0] == ' ')
			x++;
	}
	printf("x %d y %d", x, y);
	return (1);
}




int		ft_check_file(int fd)
{
	size_t n;
	char	buf[1];
	int		x;
	int		y;

	n = 0;
	x = 0;
	y = 0;
	while ((n = read(fd, buf, 1)))
	{
		if (buf[0] != ' ' && buf[0] != '.' && buf[0] != '#' && buf[0] != '\n')
			return (0);
	}
	return (1);
}

