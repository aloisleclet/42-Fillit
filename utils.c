/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 09:52:11 by aleclet           #+#    #+#             */
/*   Updated: 2017/03/02 13:08:06 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// print tetri from table and n 

void	ft_print_tetri_map(char **table)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < 4)
	{
		while (i < 4)
		{
			ft_putchar(table[j][i]);
			i++;
		}
		ft_putchar('\n');
		i = 0;
		j++;
	}
	ft_putchar('\n');
}

//print tetri from pos

void	ft_print_tetri_pos(int pos[4][2])
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		while (x < 4)
		{
			if (pos[0][0] == x && pos[0][1] == y)
				printf("#");
			else if (pos[1][0] == x && pos[1][1] == y)
				printf("#");
			else if (pos[2][0] == x && pos[2][1] == y)
				printf("#");
			else if (pos[3][0] == x && pos[3][1] == y)
				printf("#");
			else
				printf(".");
			x++;
		}
		printf("\n");
		x = 0;
		y++;	
	}
}

//print tetri from bin

void	ft_print_bin(unsigned char **bin, int nb)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < nb)
	{
		printf("tetri %d \n", i);
		printf("%c%c\n", bin[i][0], bin[i][1]);
		while (j < 18)
		{
			printf("%c", bin[i][j + 2]);
			j++;
			if (j % 4 == 0)
				printf("\n");
		}
		j = 0;
		i++;
		printf("\n");
	}
}

char	***ft_alloc_table(char ***table, int n)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!(table = (char***)malloc(sizeof(char**) * (n + 1))))
		return (NULL);
	while ((n--))
	{
			table[n] = (char **)malloc(sizeof(char**) * 5);
		while (y < 4)
		{
			table[n][y] = (char *)malloc(sizeof(char*) * 5);
			x = 0;
			y++;
		}
		y = 0;
	}
	return (table);
}

char	***ft_fill_table(char ***table, char *filename)
{
	int		x;
	int		y;
	int		i;
	char	buf[1];
	int		fd;

	x = 0;
	y = 0;
	i = 0;
	fd = ft_open_file(filename);
	while (read(fd, buf, 1))
	{
		x = (buf[0] == '\n') ? 0 : x;
		i = (buf[0] == '\n') ? 0 : i;
		y = (buf[0] == '\n') ? y + 1 : y;
		i = (buf[0] == ' ') ? i + 1 : i;
		x = (buf[0] == ' ') ? 0 : x;
		if (buf[0] != ' ' && buf[0] != '\n')
		{
			table[i][y][x] = buf[0];
			x++;
		}
	}
	return (table);
}

// 2D table with binary value

unsigned char	**ft_file_to_table_bin(char *filename, unsigned char **bin, int nb)
{
	int		i;
	int		j;
	int		k;
	char	buf[1];
	int		fd;

	i = 0;
	j = 0;
	k = 0;
	fd = ft_open_file(filename);
	bin = (unsigned char**)malloc(sizeof(unsigned char*) * (nb + 1));
	
	while ((nb--))
	{
		bin[nb] = (unsigned char*)malloc(sizeof(unsigned char) * (18 + 1));
		bin[nb][0] = '0';
		bin[nb][1] = 'b';
	}

	while (read(fd, buf, 1))
	{
		if (buf[0] == ' ')
		{
			j = 2;
			i++;
		}
		else if (buf[0] == '\n')
		{
			i = 0;
			j = 2;
			k += 4;
		}
		if (buf[0] != '\n' && buf[0] != ' ')
		{
			bin[i][k + j] = (buf[0] == '.') ? '0' : '1';
			j++;
		}
	}
	return (bin);
}

//Size of the file and some check buf there is some bug here

int		ft_size(char *filename, int size[]) //something goes wrong here ..
{
	int		fd;
	char	buf[1];
	int		last;

	fd = ft_open_file(filename);
	last = -1;
	while (read(fd, buf, 1))
	{
		size[0] += 1;
		if (buf[0] == '\n')
		{
			size[1] += 1;
			last = (last == size[0] || last == -1) ? size[0] : last;
			size[0] = (last == size[0] || last == -1) ? size[0] : size[0];
			if (!(last == size[0] || last == -1))
				return (0);	
		}
		if (buf[0] != ' ' && buf[0] != '\n' && buf[0] != '.' && buf[0] != '#')
			return (0);
	}
	size[0] = last;
	close(fd);
	return (1);
}

