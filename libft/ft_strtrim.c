/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarouac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 00:56:22 by fkarouac          #+#    #+#             */
/*   Updated: 2019/07/29 00:56:25 by fkarouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define WS(c) (c == ' ' || c == '\t' || c == '\n')

char	*ft_strtrim(char const *s)
{
	size_t		start;
	size_t		end;
	char		*str;

	start = 0;
	str = NULL;
	if (!s)
		return (NULL);
	end = ft_strlen(s) - 1;
	while (WS(((char*)s)[end]) && end)
		end--;
	while (WS(((char*)s)[start]))
		start++;
	if (end < start)
		return (ft_strnew(0));
	end = end - start;
	str = ft_strsub(s, start, end + 1);
	return (str);
}
