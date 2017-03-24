/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 02:18:18 by ksaetern          #+#    #+#             */
/*   Updated: 2017/03/22 02:18:32 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_remove(char **map, t_tetri *tetris)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (map[x] != '\0')
	{
		y = 0;
		while (map[x][y] != '\0')
		{
			if (map[x][y] == tetris->letter)
				map[x][y] = '.';
			y++;
		}
		x++;
	}
}

void		ft_placepiece(char **map, t_tetri *tetris, int x, int y)
{
	int				i;

	i = 3;
	while (i >= 0)
	{
		map[x + tetris->xpos[i]][y + tetris->ypos[i]] = tetris->letter;
		i--;
	}
}

int			ft_setvalid(char **map, t_tetri *tetris, int xcurr, int ycurr)
{
	int			i;
	int			j;
	int			k;

	j = 0;
	i = 0;
	while (map[j] != '\0')
	{
		k = 0;
		while (map[j][k] != '\0')
		{
			if (map[j][k] == '.' && (tetris->xpos[i] + xcurr) == j &&
				(tetris->ypos[i] + ycurr) == k)
				i++;
			k++;
		}
		j++;
	}
	if (i < 4)
		return (0);
	return (1);
}
