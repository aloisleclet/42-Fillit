/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 11:24:41 by aleclet           #+#    #+#             */
/*   Updated: 2017/07/06 12:57:42 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = -1;
	while (str[i++])
		ft_putchar(str[i]);
}

int		ft_strlen(char *s)
{
	int		i;

	i = 0;

	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return ((void*)(0));
	res = (char*)(malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2))));
	if (res != (void*)(0))
	{
		while (*(s1 + j))
		{
			*(res + (i++)) = *(s1 + j);
			j++;
		}
		j = 0;
		while (*(s2 + j))
		{
			*(res + (i++)) = *(s2 + j);
			j++;
		}
		*(res + i) = '\0';
	}
	return (res);
}

void	ft_read(char *filename)
{
	int		n;
	int		fd = 0;
	char	buf[1];

	n = 0;
	fd = open(filename, O_RDONLY);
	while ((n = read(fd, buf, 1)))
	{
		ft_putchar(buf[0]);
					
	}
}

int		ft_fillit(int argc, char **argv)
{
	ft_read(argv[1]);
	return (1);
}

