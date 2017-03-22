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
	newlist->prev = newlist;
	if (!(newlist->next = (t_tetri *)malloc(sizeof(t_tetri))))
		return (0);
	newlist = newlist->next;
	return (newlist);
}

t_tetri		*readchecks(int fd)
{
	t_tetri		*tetris;
	t_tetri		*newlist;
	char		str[21];
	int			i;
	int			curr;
	int			last;

	i = 0;	
	if (!(tetris = (t_tetri *)malloc(sizeof(t_tetri))))
		return (0);
	newlist = tetris;
	while ((curr = read(fd, str, 21)))
	{
		printf("initializing read checking: %d block\n", curr);
		printf("%s", str);
		str[curr] = '\0';
		last = curr;
		if (validcheck(str) != 1)
			return (0);
		newlist = ft_store(str, i, newlist);
		i++;
		newlist = ft_newlist(newlist);
		printf("valid tetri = %d\n", i);
	}
	newlist->next = NULL;
	printf("last = %d\n", last);
	if (last != 20 || i > 26)
		return (NULL);
	ft_putendl("you passed\n");
	close(fd);
	return (tetris);
}
