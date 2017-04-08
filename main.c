/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 04:23:55 by ksaetern          #+#    #+#             */
/*   Updated: 2017/03/14 16:28:53 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_printmap(char **map)
{
	int		i;

	i = 0;
	while (*map)
		ft_putendl(*map++);
	while (map[i] != '\0')
	{
		free(map[i]);
		i++;
	}
}

int		ft_error(char *str, int o)
{
	ft_putendl(str);
	return (o);
}

void	ft_deletelist(t_tetri *tetris)
{
	t_tetri		*next;

	while (tetris != NULL)
	{
		next = tetris->next;
		tetris->next = NULL;
		free(tetris);
		tetris = next;
	}
	tetris = NULL;
}

int		main(int argc, char **argv)
{
	int			fd;
	t_tetri		*tetris;
	char		**solved;

	if (argc != 2)
		return (ft_error("usage: ./fillit User_File", 0));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error("error", 0));
	tetris = ft_readchecks(fd, 0);
	if (tetris == NULL)
		return (ft_error("error", 0));
	solved = ft_solved(tetris);
	ft_printmap(solved);
	free(solved);
	ft_deletelist(tetris);
	return (0);
}
