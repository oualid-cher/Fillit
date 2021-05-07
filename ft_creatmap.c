/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creatmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarouac <fkarouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 12:08:26 by fkarouac          #+#    #+#             */
/*   Updated: 2019/09/30 01:46:54 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_setmap(int x, int y)
{
	int		i;
	int		j;
	char	**map;

	j = 0;
	map = (char **)malloc(sizeof(char *) * (y + 1));
	while (j < y)
	{
		i = 0;
		map[j] = (char *)malloc(sizeof(char) * (x + 1));
		while (i < x)
		{
			map[j][i] = '.';
			i++;
		}
		map[j][i] = '\0';
		j++;
	}
	map[j] = NULL;
	return (map);
}

int		ft_squareside(char *tetrimino)
{
	int		x;
	int		sqr;
	int		res;
	int		surface;

	x = 0;
	sqr = 0;
	res = 0;
	surface = (ft_counttetrimino(tetrimino) * 4);
	while (res < surface)
	{
		res = x * sqr;
		x++;
		sqr++;
	}
	x--;
	return (x);
}

t_map	*ft_map(char *tetrimino)
{
	t_map	*map;
	int		x;
	int		y;

	x = ft_squareside(tetrimino);
	y = x;
	map = (t_map *)malloc(sizeof(t_map));
	map->map = ft_setmap(x, y);
	map->xmax = x;
	map->ymax = y;
	return (map);
}

void	ft_freemap(t_map **map)
{
	int	i;

	i = 0;
	while (i < (*map)->xmax)
	{
		free((*map)->map[i]);
		i++;
	}
	free((*map)->map);
	free(*map);
}

t_map	*ft_resizemap(t_map *firstmap)
{
	t_map	*map;
	int		x;
	int		y;

	x = firstmap->xmax + 1;
	y = firstmap->ymax + 1;
	map = (t_map *)malloc(sizeof(t_map));
	map->map = ft_setmap(x, y);
	map->xmax = x;
	map->ymax = y;
	return (map);
}
