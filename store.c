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

/*
it looks messier then it is.
what im storing is something i can use to place my tetrimino on a 2d array, my map
Find the first hashtag
store where you find it in x1 and y1
now everytime you find another hashtag,
subtract the newest position x,y to the first x,y you found of the first hastag
this will give you a distance to the first hashtag
which can be used to form any tetrimino

this is our tetrimino E
.##.\n
..##\n

first hash is at [0,1]. y1 = 0, x1 = 1
secondHash = [0,2]
you would store 

xpos[i] = k - x1
ypos[i] = j - y1
which ==
xpos[i] = 0 - 0 = 0
ypos[i] = 2 - 1 = 1

thirdHash = [1,2]
store:
xpos[i] = 1 - 0 = 1
ypos[i] = 2 - 1 = 1

4thHash = [1,3]
store:
xpos[i] = 1 - 0 = 1
ypos[i] = 3 - 1 = 2

so we stored into our array
x | y
0   0
0   1
1   1
1   2

so if we have a 2d array as our solution map

AABCC
AABBC
D..BC
DD...
D....

E needs to go

AABCC
AABBC
DEEBC
DDEE.
D....

you can count it, the valid position for the E piece is at
[2,1]
[2,2]
[3,2]
[3,3]


AABCC
AABBC
D..BC //the first valid position is at [2,1] here
DD...
D....

so now add in your stored numbers to the first valid position
[2,1] + y | x
[2,1] + 0 , 0
[2,1] + 0 , 1
[2,1] + 1 , 1
[2,1] + 1 , 2

to the first valid position, [2,1]
2 + 0, 1 + 0 = 2,1
2 + 0, 1 + 1 = 2,2
2 + 1, 1 + 1 = 3,2
2 + 1, 1 + 2 = 3,3

well look at that, the numbers you store earlier,
if added to any valid positions on a 2d array will form the shape of your tetrimino

*/

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

/*
i and j = 0 and initialized in the parameter just to save lines, trick can be used in all places to help with norm
i keeps track of how many # you find, really just so you know which is the first hashtag you find

*/
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
	return (*newtetri);
}

/*
great you have a valid tetrimino on your hands, now what?
store only information that can help you place your tetrimino on to your map
i is 0 the first link
i will be 1 on the second link, 'A' + 1 = 'B'

*/

t_tetri		*ft_store(char *str, int i, t_tetri *newlist)
{
	char		**grid;

	newlist->letter = 'A' + i;
	grid = ft_strsplit(str, '\n');//str split to make it easier to deal with
	ft_storexy(grid, newlist, 0, 0); // initialize i and j to 0 so you save lines
	return (*&newlist);// lol this is terrible coding, i dont remember why i did this
}
