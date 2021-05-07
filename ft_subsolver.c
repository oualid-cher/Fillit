/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subsolver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarouac <fkarouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:22:42 by fkarouac          #+#    #+#             */
/*   Updated: 2019/10/01 21:00:23 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_isvalidcoord(t_tetrimino *tet, t_map *map, int x, int y)
{
	if (x + tet->x[1] < 0 || y + tet->y[1] < 0)
		return (0);
	if (x + tet->x[2] < 0 || y + tet->y[2] < 0)
		return (0);
	if (x + tet->x[3] < 0 || y + tet->y[3] < 0)
		return (0);
	if (x + tet->x[1] > map->xmax - 1 || y + tet->y[1] > map->ymax - 1)
		return (0);
	if (x + tet->x[2] > map->xmax - 1 || y + tet->y[2] > map->ymax - 1)
		return (0);
	if (x + tet->x[3] > map->xmax - 1 || y + tet->y[3] > map->ymax - 1)
		return (0);
	return (1);
}

int		ft_isemptyposition(t_tetrimino *tet, t_map *map, int x, int y)
{
	if (map->map[y][x] != '.')
		return (0);
	if (map->map[y + tet->y[1]][x + tet->x[1]] != '.')
		return (0);
	if (map->map[y + tet->y[2]][x + tet->x[2]] != '.')
		return (0);
	if (map->map[y + tet->y[3]][x + tet->x[3]] != '.')
		return (0);
	return (1);
}

int		ft_loadposition(t_tetrimino *tet, t_map *map, int x, int y)
{
	if (ft_isvalidcoord(tet, map, x, y) == 0)
		return (0);
	else if (ft_isemptyposition(tet, map, x, y) == 0)
		return (0);
	else
	{
		map->map[y][x] = tet->c;
		map->map[y + tet->y[1]][x + tet->x[1]] = tet->c;
		map->map[y + tet->y[2]][x + tet->x[2]] = tet->c;
		map->map[y + tet->y[3]][x + tet->x[3]] = tet->c;
	}
	return (1);
}

void	ft_clearposition(t_tetrimino *tet, t_map *map, int x, int y)
{
	map->map[y][x] = '.';
	map->map[y + tet->y[1]][x + tet->x[1]] = '.';
	map->map[y + tet->y[2]][x + tet->x[2]] = '.';
	map->map[y + tet->y[3]][x + tet->x[3]] = '.';
}

void	ft_printmap(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		ft_putendl(map[i]);
		i++;
	}
}
