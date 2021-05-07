/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrimino.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarouac <fkarouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 10:10:45 by fkarouac          #+#    #+#             */
/*   Updated: 2019/10/01 21:00:31 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_isvalidtet(char *tetrimino)
{
	int		count;

	count = (ft_strlen(tetrimino) + 1) / 21;
	if (ft_isvalidchar(tetrimino) && ft_isvalidcount(tetrimino) &&
		ft_isvalidformat(tetrimino) && ft_checkneig(tetrimino, 0) &&
		count <= 26)
		return (1);
	else
		return (0);
}

char	*ft_rdtetrimino(char *filename)
{
	int		fd;
	int		ret;
	char	*tetrimino;
	char	tmp[21];
	char	*tmp1;

	fd = open(filename, O_RDONLY);
	tetrimino = ft_strnew(0);
	while ((ret = read(fd, tmp, 21)) > 0)
	{
		tmp1 = tetrimino;
		tmp[ret] = '\0';
		tetrimino = ft_strjoin(tetrimino, tmp);
		ft_strdel(&tmp1);
	}
	if (!ft_isvalidtet(tetrimino) || ret < 0)
	{
		ft_strdel(&tetrimino);
		return (NULL);
	}
	return (tetrimino);
}
