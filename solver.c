/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:12:43 by aleclet           #+#    #+#             */
/*   Updated: 2017/03/08 14:58:40 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**alloc_map(char **map, int n)
{
	printf("alloc\n");
	int		j;
	int		i;

	j = 0;
	i = 0;
	map = (char**)malloc(sizeof(char**) * (n + 1));
	while (j < n)
	{
		*(map + j) = (char*)malloc(sizeof(char*) * (n + 1));
		j++;
	}

	i = 0;
	j = 0;

	while (j < n)
	{
		while (i < n)
		{
			map[j][i] = '.';
			i++;	
		}
		i = 0;
		j++;
	}
	return (map);
}

void	print_map(char **map, int n)
{
	printf("print\n");
	int		j;
	int		i;

	i = 0;
	j = 0;

	while (j < n)
	{
		while (i < n)
		{
			printf("%c", map[j][i]);
			i++;
		}	
		i = 0;	
		j++;
		printf("\n");
	}
}

void	put_tetri_on_map(int pos_x[4], int pos_y[4], char **map, int n)
{
	printf("put\n");
	int		i;
	int		j;

	i = 0;
	j = 0; 

	//tant qu'il y'a pas de # ou que je suis pas le plus en haut a gauche possible, decaler tetris
//	return 1 if the tetris find place
// return 0 if the tetris have no place
// return -1 if there is an error
}

int		solve(char ***table)
{
	int		i;
	int		size;
	int		pos_x[4];
	int		pos_y[4];
	char	**map;

	size = 4;
	i = 0;
	map = NULL;

	printf("solve\n");

	map = alloc_map(map, size);
	put_tetri_on_map(pos_x, pos_y, map, size);

	printf("while\n");
	while (i < size)
	{
		map_to_tetri_pos(*(table + i), pos_x, pos_y);
		printf("i :  %d -x \n", i);
		put_tetri_on_map(post_x, post_y, map, size);	
		i++;
	}

	print_map(map, size);

	return (0);
}
