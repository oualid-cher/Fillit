/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extractet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarouac <fkarouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:05:45 by fkarouac          #+#    #+#             */
/*   Updated: 2019/10/01 20:59:44 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrimino		*ft_tetmalloc(void)
{
	t_tetrimino		*tet;

	(tet = (t_tetrimino *)malloc(sizeof(t_tetrimino)));
	if (tet == NULL)
		return (NULL);
	return (tet);
}

int				ft_tetorigin(char *tetrimino, int i)
{
	while (tetrimino[i] != '#')
		i++;
	return (i);
}

t_tetrimino		*ft_extractone(char *tetrimino, int index)
{
	t_tetrimino		*onetet;
	int				i;
	int				row;
	int				box;

	i = 0;
	row = 0;
	index = ft_tetorigin(tetrimino, index);
	box = index;
	onetet = ft_tetmalloc();
	while (i < 4)
	{
		if (tetrimino[index] == '\n')
		{
			row++;
			box += 5;
		}
		if (tetrimino[index] == '#')
		{
			onetet->x[i] = (index - box);
			onetet->y[i++] = row;
		}
		index++;
	}
	return (onetet);
}

t_tetrimino		**ft_extractall(char *tetrimino)
{
	t_tetrimino		**alltet;
	int				tet_count;
	int				i;
	int				j;
	char			c;

	tet_count = ft_counttetrimino(tetrimino);
	alltet = (t_tetrimino**)malloc(sizeof(t_tetrimino*) * (tet_count + 1));
	i = 0;
	j = 0;
	c = 'A';
	while (j < tet_count)
	{
		alltet[j] = ft_extractone(tetrimino, i);
		alltet[j]->c = c;
		c++;
		i += 21;
		j++;
	}
	alltet[j] = NULL;
	return (alltet);
}
