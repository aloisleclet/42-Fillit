/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 11:24:41 by aleclet           #+#    #+#             */
/*   Updated: 2017/07/08 12:05:03 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	get_file(char *filename)
{
	int		n;
	int		fd;
	char	buf[547];
	char	*str;

	n = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	if (!(str = (char *)(sizeof(char))))
		return (0);
	ft_bzero(buf);
	if (n = read(fd, buf, 546) && n != -1)
		str = ft_strdup(buf);
	return (str);
}

int		ft_fillit(int argc, char **argv)
{
	ft_read(argv[1]);
	return (1);
}
