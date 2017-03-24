/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:29:31 by ksaetern          #+#    #+#             */
/*   Updated: 2017/03/14 16:29:37 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*ft_newlist(t_tetri *newlist)
{
	if (!(newlist->next = (t_tetri *)malloc(sizeof(t_tetri))))
		return (0);
	newlist = newlist->next;
	return (newlist);
}

t_tetri		*ft_readchecks(int fd, int i)
{
	t_tetri		*tetris;
	t_tetri		*newlist;
	char		str[21];
	int			curr;
	int			last;

	if (!(tetris = (t_tetri *)malloc(sizeof(t_tetri))))
		return (0);
	newlist = tetris;
	while ((curr = read(fd, str, 21)))
	{
		str[curr] = '\0';
		last = curr;
		if (ft_validcheck(str) != 1)
			return (0);
		newlist = ft_store(str, i, newlist);
		i++;
		newlist = ft_newlist(newlist);
	}
	newlist->next = NULL;
	if (last != 20 || i > 26)
		return (NULL);
	close(fd);
	return (tetris);
}
