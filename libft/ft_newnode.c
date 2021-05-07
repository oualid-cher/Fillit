/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarouac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 00:15:55 by fkarouac          #+#    #+#             */
/*   Updated: 2019/07/29 00:16:02 by fkarouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_newnode(int fd, char *str)
{
	t_node	*node;

	if (!(node = malloc(sizeof(t_node))))
		return (NULL);
	node->next = NULL;
	if (!(node->str = malloc(sizeof(ft_strlen(str) + 1))))
		return (NULL);
	node->fd = fd;
	node->str = ft_strcpy(node->str, str);
	node->next = NULL;
	return (node);
}
