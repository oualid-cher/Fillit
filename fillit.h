/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarouac <fkarouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 21:52:17 by fkarouac          #+#    #+#             */
/*   Updated: 2019/10/01 20:59:13 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H
# include "./libft/libft.h"

typedef struct	s_content
{
	int		count_hash;
	int		count_dot;
	int		count_newline;
}				t_content;
typedef struct	s_tetrimino
{
	int		x[4];
	int		y[4];
	char	c;
}				t_tetrimino;
typedef struct	s_map
{
	char	**map;
	int		xmax;
	int		ymax;
}				t_map;
char			*ft_concatrd(char *tetrimino, int size);
void			ft_doublestrdel(char **s1, char **s2);
char			*ft_rdtetrimino(char *filename);
int				ft_isvalidtet(char *tetrimino);
int				ft_isvalidchar(char *tetrimino);
t_content		*ft_countcontent(char *tetrimino);
int				ft_isvalidcount(char *tetrimino);
int				ft_counttetrimino(char *tetrimino);
int				ft_isvalidformat(char *tetrimino);
int				ft_onetet(char *tetrimino, int i);
int				ft_multitet(char *tetrimino, int tet);
int				ft_countneig(char *tetrimino, int i);
int				ft_checkneig(char *tetrimino, int i);
t_tetrimino		*ft_tetmalloc(void);
int				ft_tetorigin(char *tetrimino, int i);
t_tetrimino		*ft_extractone(char *tetrimino, int index);
t_tetrimino		**ft_extractall(char *tetrimino);
char			**ft_setmap(int x, int y);
int				ft_squareside(char *tetrimino);
char			**ft_creatmap(char *tetrimino);
t_map			*ft_map(char *tetrimino);
t_map			*ft_resizemap(t_map *firstmap);
int				ft_isvalidcoord(t_tetrimino *tet, t_map *map, int x, int y);
int				ft_isemptyposition(t_tetrimino *tet, t_map *map, int x, int y);
int				ft_loadposition(t_tetrimino *tet, t_map *map, int x, int y);
void			ft_clearposition(t_tetrimino *tet, t_map *map, int x, int y);
void			ft_printmap(char **map);
void			ft_freemap(t_map **map);
t_map			*ft_fillit(char *tetrimino);
int				ft_backtracking(t_tetrimino **alltet, t_map *map, int i);
#endif
