/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:59:30 by ksaetern          #+#    #+#             */
/*   Updated: 2017/03/16 18:59:49 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


/*
start with a 2x2
because 1 tetrimino could be 
##
##

keep increasing size until you have the minimum sized map to fit your tetrimino

4 square tetriminos

####
####
####
####

at minimum need 4x4 2d array
16 spots to fill it up



*/
int			ft_mapmin(t_tetri *tetri)
{
	int		size;
	int		i;

	i = -1;
	while (tetri != NULL)
	{
		i++;
		tetri = tetri->next;
	}
	size = 2;
	while ((size * size) - (i * 4) < 0)
		size++;
	return (size);
}

// make your 2d array and fill it up
char		**ft_mapmaker(int max)
{
	int		x;
	int		y;
	char	**map;

	x = 0;
	if (!(map = (char **)malloc(sizeof(char *) * (max + 1))))
		return (NULL);
	map[max] = NULL;
	while (x < max)
	{
		if (!(map[x] = (char*)malloc(sizeof(char) * max)))
			return (NULL);
		y = 0;
		while (y < max)
		{
			map[x][y] = '.';
			y++;
		}
		x++;
	}
	return (map);
}
