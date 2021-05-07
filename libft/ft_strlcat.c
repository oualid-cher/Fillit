/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarouac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 00:51:57 by fkarouac          #+#    #+#             */
/*   Updated: 2019/07/29 00:51:59 by fkarouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_size;
	size_t	d_size;
	int		i;

	s_size = ft_strlen(src);
	d_size = ft_strlen(dst);
	i = 0;
	while (size > d_size + i + 1 && src[i])
	{
		dst[d_size + i] = src[i];
		i++;
	}
	dst[d_size + i] = '\0';
	if (size >= d_size)
		return (s_size + d_size);
	else
		return (s_size + size);
}
