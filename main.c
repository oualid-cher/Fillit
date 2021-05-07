/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarouac <fkarouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 22:36:49 by fkarouac          #+#    #+#             */
/*   Updated: 2019/10/01 21:00:37 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char	*tet;
	t_map	*map;

	if (ac != 2)
	{
		ft_putendl("usage: fillit entry_file");
		return (0);
	}
	if (!(tet = ft_rdtetrimino(av[1])))
	{
		ft_putendl("error");
		return (-1);
	}
	map = ft_fillit(tet);
	ft_printmap(map->map);
	ft_strdel(&tet);
	ft_freemap(&map);
	return (0);
}
