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


/*
create a linked list, each struct to store infomation about 1 tetrimino
read 21 bytes at a time, check read string for validation

*/
t_tetri		*ft_readchecks(int fd, int i)
{
	t_tetri		*tetris;
	t_tetri		*newlist;
	char		str[21];
	int			curr;
	int			last;

	if (!(tetris = (t_tetri *)malloc(sizeof(t_tetri))))
		return (0);//keep tetris as the head of your list so you know where the first in the list is
	newlist = tetris;//use the newlist pointer to keep adding on to your list
	while ((curr = read(fd, str, 21)))//read 21 bytes at a time, 4 lines read = 20 + 1 for \n
	{
		str[curr] = '\0';
		last = curr;//store number of read bytes as another validation checker, last tetri should only read 20
		if (ft_validcheck(str) != 1)//go to check.c
			return (0);
		newlist = ft_store(str, i, newlist);//go to store.c
		i++;//i is used to keep track of letter of tetrimino
		newlist = ft_newlist(newlist);
	}
	newlist->next = NULL;
	if (last != 20 || i > 26) // last tetrimino read shouldnt have new line, so read should = 20
		return (NULL);
	close(fd);
	return (tetris);//tetris pointer because that is the head of your list, the first of your linked list
}
