/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:29:55 by ksaetern          #+#    #+#             */
/*   Updated: 2017/03/14 16:29:58 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
Each valid tetrimino should a total of 6 or 8 connections.
connection: for each individual hashtag, it should have hashtag to the left, right, above or below it.
##
## has 8 connections, each hashtag has two hashtags connected to it
all other valid tetrimino has 6
##
 ## has 6 connections, first hash has 1 connection, second has 2, third has 2, last one has 1

with respect to edge cases like 'i' being 0 or at the end or first row or last row
if you are checkin in a string,
+1 check right
-1 check left
+5 check below
-5 check above

if easier, def can string split the str
*/
int		ft_connect_check(char *str)
{
	int		con;
	int		i;

	i = 0;
	con = 0;
	while (i <= 20)
	{
		if (str[i] == '#')
		{
			if ((i - 1) >= 0 && str[i - 1] == '#')
				con++;
			if ((i + 1) < 20 && str[i + 1] == '#')
				con++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				con++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				con++;
		}
		i++;
	}
	if (con == 6 || con == 8)
		return (1);
	else
		return (0);
}



int		ft_size_check(char *str, int hash, int y, int x)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] == '#' || str[i] == '.' || str[i] == '\n'))
			return (0);// should only contain 1 of 3 characters
		if (str[i] == '#')
			hash++;// total of 4 hashes needed
		if (str[i] == '.' || str[i] == '#')
			y++;//valid character
		if (str[i] == '\n')// by the time you read a \n, you should have 4 valid characters
		{
			if (y == 4)
				x++;//you have a valid line
			y = 0;
		}
		i++;
	}
	if (hash == 4 && x == 4)
		return (1);
	else
		return (0);
}

int		ft_validcheck(char *str)
{
	if (str == NULL)
		return (ft_error("error", 0));
	if (ft_connect_check(str) == 1 && ft_size_check(str, 0, 0, 0) == 1)
		return (1);
	else
		return (0);
}
