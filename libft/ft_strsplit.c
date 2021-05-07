/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarouac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 00:55:37 by fkarouac          #+#    #+#             */
/*   Updated: 2019/07/29 00:55:40 by fkarouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(const char *s, char c)
{
	int index;
	int in_word;
	int count;

	index = 0;
	in_word = 0;
	count = 0;
	while (s[index] != '\0')
	{
		if (s[index] == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		index++;
	}
	return (count);
}

static int		word_length(const char *s, int index, char c)
{
	int		length;

	length = 0;
	while (s[index] != c && s[index] != '\0')
	{
		length++;
		index++;
	}
	return (length);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**words;
	int		s_index;
	int		w_index;
	int		index;

	s_index = 0;
	w_index = 0;
	if (!s)
		return (0);
	if (!(words = (char**)malloc(sizeof(char*) * count_words(s, c) + 1)))
		return (0);
	while (s[s_index] != '\0' && w_index < count_words(s, c))
	{
		index = 0;
		while (s[s_index] == c)
			s_index++;
		words[w_index] = ft_strnew(word_length(s, s_index, c));
		while (s[s_index] != c && s[s_index] != '\0')
			words[w_index][index++] = s[s_index++];
		words[w_index][index] = '\0';
		w_index++;
	}
	words[w_index] = 0;
	return (words);
}
