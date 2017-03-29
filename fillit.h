/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:25:40 by ksaetern          #+#    #+#             */
/*   Updated: 2017/03/23 17:16:28 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>

typedef	struct		s_tetri
{
	int				h;
	int				w;
	int				x1;
	int				y1;
	int				xpos[5];
	int				ypos[5];
	char			letter;
	struct s_tetri	*next;
}					t_tetri;

int					ft_connect_check(char *str);
int					ft_size_check(char *str, int hash, int y, int x);
int					ft_validcheck(char *str);
t_tetri				*ft_readchecks(int fd, int i);
t_tetri				*ft_newlist(t_tetri *newlist);
void				ft_putendl(char const *s);
t_tetri				*ft_store(char *str, int i, t_tetri *tmp);
t_tetri				ft_storexy(char **str, t_tetri *newtetri, int j, int i);
char				**ft_strsplit(char const *s, char c);
void				ft_xydistance(t_tetri *newtetri, int j, int k, int i);
int					ft_mapmin(t_tetri *tetri);
char				**ft_mapmaker(int max);
char				**ft_solved(t_tetri *tetris);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strnew(size_t size);
void				ft_printmap(char **map);
int					ft_setvalid(char **map, t_tetri *tetris, int xcurr,
					int ycurr);
void				ft_placepiece(char **map, t_tetri *tetris, int x, int y);
void				ft_remove(char **map, t_tetri *tetris);
int					ft_rocket(char **map, t_tetri *tetris, int max);
int					ft_error(char *str, int o);
int					ft_superrocket(char **map, t_tetri *tetris, int max);
void				ft_deletelist(t_tetri *tetris);

#endif
