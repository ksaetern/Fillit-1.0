/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:23:39 by ksaetern          #+#    #+#             */
/*   Updated: 2017/03/16 18:24:06 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_rocket(char **map, t_tetri *tetris, int max)
{
	int			x;
	int			y;

	x = 0;
	if (tetris->next == NULL)
		return (1);
	while (map[x] != '\0' && (x + tetris->h) <= max)
	{
		y = 0;
		while (map[x][y] != '\0' && (y + tetris->w) <= max)
		{
			while (map[x][y] >= 'A' && map[x][y] <= 'Z')
				y++;
			if (ft_setvalid(map, tetris, x, y))
			{
				ft_placepiece(map, tetris, x, y);
				if (ft_rocket(map, tetris->next, max))
					return (1);
				ft_remove(map, tetris);
			}
			y++;
		}
		x++;
	}
	return (0);
}

char		**ft_solved(t_tetri *tetris)
{
	char		**map;
	int			max;

	max = ft_mapmin(tetris);
	map = ft_mapmaker(max);
	while (ft_rocket(map, tetris, max) != 1)
	{
		free(map);
		max++;
		map = ft_mapmaker(max);
	}
	return (map);
}
