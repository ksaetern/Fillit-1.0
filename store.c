/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:50:24 by ksaetern          #+#    #+#             */
/*   Updated: 2017/03/14 16:50:35 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_xydistance(t_tetri *newtetri, int j, int k, int i)
{
	if (i == 0)
	{
		newtetri->x1 = j;
		newtetri->y1 = k;
		newtetri->ypos[i] = k - k;
		newtetri->xpos[i] = j - j;
		newtetri->w = 0;
		newtetri->h = 0;
	}
	else
	{
		newtetri->ypos[i] = k - newtetri->y1;
		newtetri->xpos[i] = j - newtetri->x1;
		if (newtetri->w < newtetri->ypos[i])
			newtetri->w = newtetri->ypos[i];
		if (newtetri->h < newtetri->xpos[i])
			newtetri->h = newtetri->xpos[i];
	}
}

t_tetri		ft_storexy(char **str, t_tetri *newtetri, int j, int i)
{
	int		k;

	while (str[j] != '\0')
	{
		k = 0;
		while (str[j][k])
		{
			if (str[j][k] == '#')
			{
				ft_xydistance(newtetri, j, k, i);
				i++;
			}
			k++;
		}
		j++;
	}
	newtetri->ypos[4] = '\0';
	newtetri->xpos[4] = '\0';
	return (*newtetri);
}

t_tetri		*ft_store(char *str, int i, t_tetri *newlist)
{
	char		**grid;

	newlist->letter = 'A' + i;
	grid = ft_strsplit(str, '\n');
	ft_storexy(grid, newlist, 0, 0);
	return (*&newlist);
}
