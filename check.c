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
			return (0);
		if (str[i] == '#')
			hash++;
		if (str[i] == '.' || str[i] == '#')
			y++;
		if (str[i] == '\n')
		{
			if (y == 4)
				x++;
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
