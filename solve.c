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

//added for debuggin purpose
//just to show you the map working and the recursive back tracking
void testMap(char **map, char letter, char *Message)
{
	ft_putendl(Message);
	ft_putendl(&letter);
	while (*map)
		ft_putendl(*map++);
	ft_putendl("");
}

/*
my recursive back tracking
yeah bad x,y system 

to be explained letter,
message if you need this
*/

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
				//Debug>
				//debugging area added for your benefit,
				// uncomment testMaps to see recursive back tracking working
				//testMap(map, tetris->letter, "Add Piece");
				//<Debug
				if (ft_rocket(map, tetris->next, max))
					return (1);
				ft_remove(map, tetris);
				//Debug>
				//testMap(map, tetris->letter, "Remove Piece");
				//<Debug
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

	ft_putendl("In solved");
	max = ft_mapmin(tetris);//map.c
	map = ft_mapmaker(max);//map.c
	while (ft_rocket(map, tetris, max) != 1)
	{
		//ft_putendl("remake");
		free(map);
		max++;
		map = ft_mapmaker(max);
	}
	return (map);
}
