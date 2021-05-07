/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarouac <fkarouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 21:11:16 by fkarouac          #+#    #+#             */
/*   Updated: 2019/10/01 21:00:13 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_backtracking(t_tetrimino **alltet, t_map *map, int i)
{
	int		x;
	int		y;

	y = 0;
	if (alltet[i] == NULL)
		return (1);
	while (y < map->ymax)
	{
		x = 0;
		while (x < map->xmax)
		{
			if (ft_loadposition(alltet[i], map, x, y))
			{
				if (ft_backtracking(alltet, map, i + 1))
					return (1);
				else
					ft_clearposition(alltet[i], map, x, y);
			}
			++x;
		}
		++y;
	}
	return (0);
}

t_map	*ft_fillit(char *tetrimino)
{
	t_tetrimino		**alltet;
	t_map			*map;
	int				i;
	t_map			*tmp;

	i = 0;
	alltet = ft_extractall(tetrimino);
	map = ft_map(tetrimino);
	while (!(ft_backtracking(alltet, map, 0)))
	{
		tmp = map;
		map = ft_resizemap(map);
		ft_freemap(&tmp);
	}
	while (i < ft_counttetrimino(tetrimino))
	{
		free(alltet[i]);
		i++;
	}
	free(alltet);
	return (map);
}
