/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarouac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 23:17:26 by fkarouac          #+#    #+#             */
/*   Updated: 2019/08/17 21:36:33 by fkarouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node		*ft_fdexists(int fd, t_node **begin)
{
	t_node	*tmp;

	tmp = *begin;
	if (tmp)
	{
		while (tmp)
		{
			if (fd == tmp->fd)
				return (tmp);
			tmp = tmp->next;
		}
	}
	tmp = ft_newnode(fd, "\0");
	ft_addnode(begin, tmp);
	return (tmp);
}

char		*ft_joinread(char *tmp, char *buf, int ret)
{
	char	*l;

	l = tmp;
	tmp = ft_strnjoin(tmp, buf, ret);
	ft_strdel(&l);
	return (tmp);
}

int			get_next_line(int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static t_node	*list;
	t_node			*begin;
	char			*l;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	begin = list;
	list = ft_fdexists(fd, &begin);
	while (!ft_strchr(list->str, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
		list->str = ft_joinread(list->str, buf, ret);
	ret = 0;
	while ((list->str)[ret] && (list->str)[ret] != '\n')
		++ret;
	*line = ft_strsub(list->str, 0, ret);
	if ((list->str)[ret] == '\n')
		++ret;
	l = list->str;
	list->str = ft_strdup(list->str + ret);
	ft_strdel(&l);
	list = begin;
	(ret) ? ret = 1 : ft_strdel(line);
	return (ret);
}
