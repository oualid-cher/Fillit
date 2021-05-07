/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <ahmcherk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:05:06 by fkarouac          #+#    #+#             */
/*   Updated: 2019/10/01 23:58:55 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_onetet(char *tetrimino, int i)
{
	int		co;
	int		ro;

	while (tetrimino[i])
	{
		ro = 1;
		while (ro < 5)
		{
			co = 1;
			while (tetrimino[i++] != '\n')
				++co;
			if (co != 5)
				return (0);
			ro++;
		}
		if (tetrimino[i] != '\0')
			return (0);
	}
	return (1);
}

int		ft_multitet(char *tetrimino, int tet)
{
	int		i;
	int		co;
	int		ro;

	i = -1;
	while (tet-- > 1 && tetrimino[++i] != '\0')
	{
		ro = 0;
		while (++ro < 5)
		{
			co = 1;
			while (tetrimino[i] != '\n' && co++ >= 0)
				i++;
			if (co != 5)
				return (0);
			i++;
		}
		if ((ro == 5) && (tetrimino[i] != '\n'))
			return (0);
	}
	return (ft_onetet(tetrimino, ++i));
}

int		ft_isvalidformat(char *tetrimino)
{
	int		tet;
	int		res;

	tet = ((int)ft_strlen(tetrimino) + 1) / 21;
	res = 0;
	if (tet == 1)
		res = ft_onetet(tetrimino, 0);
	else
		res = ft_multitet(tetrimino, tet);
	if (res)
		return (1);
	else
		return (0);
}

int		ft_countneig(char *tetrimino, int i)
{
	int		neig;

	neig = 0;
	if (tetrimino[i - 1] == '#')
		neig++;
	if (tetrimino[i + 1] == '#')
		neig++;
	if (tetrimino[i - 5] == '#')
		neig++;
	if (tetrimino[i + 5] == '#')
		neig++;
	return (neig);
}

int		ft_checkneig(char *tetrimino, int i)
{
	int		hash_count;
	int		neig;
	int		j;

	i = 0;
	while (tetrimino[i])
	{
		j = 0;
		neig = 0;
		hash_count = 0;
		while (j++ < 21 && tetrimino[i])
		{
			if (tetrimino[i] == '#')
			{
				hash_count++;
				neig += ft_countneig(tetrimino, i);
				if (hash_count == 4 && neig < 6)
					return (0);
			}
			i++;
		}
		if (hash_count < 4 || hash_count > 4)
			return (0);
	}
	return (1);
}
