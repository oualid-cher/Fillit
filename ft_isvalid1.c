/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarouac <fkarouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 15:25:08 by fkarouac          #+#    #+#             */
/*   Updated: 2019/10/01 23:09:06 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_isvalidchar(char *tetrimino)
{
	int		i;

	i = -1;
	while (tetrimino[++i])
	{
		if (tetrimino[i] != '#' && tetrimino[i] != '.' && tetrimino[i] != '\n')
			return (0);
	}
	return (1);
}

t_content		*ft_countcontent(char *tetrimino)
{
	t_content	*count;
	t_content	*tmp;
	int			i;

	count = (t_content *)malloc(sizeof(t_content));
	count->count_hash = 0;
	count->count_dot = 0;
	count->count_newline = 0;
	i = 0;
	tmp = count;
	while (tetrimino[i])
	{
		if (tetrimino[i] == '#')
			count->count_hash++;
		if (tetrimino[i] == '.')
			count->count_dot++;
		if (tetrimino[i++] == '\n')
			count->count_newline++;
	}
	free(tmp);
	return (count);
}

int				ft_isvalidcount(char *tetrimino)
{
	t_content *count;

	count = ft_countcontent(tetrimino);
	if (count->count_hash == 0 || count->count_dot == 0)
		return (0);
	else if ((count->count_hash % 4 == 0) && (count->count_dot % 4 == 0)
			&& ((count->count_newline + 1) % 5 == 0))
		return (1);
	else
		return (0);
}

int				ft_counttetrimino(char *tetrimino)
{
	t_content	*count;

	count = ft_countcontent(tetrimino);
	if (count->count_hash != 0)
		return (count->count_hash / 4);
	return (0);
}
