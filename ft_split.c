/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:36:27 by dmaldona          #+#    #+#             */
/*   Updated: 2023/02/28 13:20:35 by dmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	number_of_words(char const *s, char c)
{
	int	current_pos;
	int	nwords;

	current_pos = 0;
	nwords = 0;
	while (s[current_pos] != '\0')
	{
		while (s[current_pos] == c)
			current_pos++;
		if (s[current_pos] != c && s[current_pos] != '\0')
			nwords++;
		while (s[current_pos] != c && s[current_pos] != '\0')
			current_pos++;
	}
	return (nwords);
}

static int	word_len(char const *s, char c, int current_pos)
{
	int	final_pos;

	final_pos = current_pos;
	while (s[final_pos] != '\0' && s[final_pos] != c)
		final_pos++;
	return (final_pos - current_pos);
}

static char	**free_split(char **s, int current_pos)
{
	while (current_pos >= 0)
	{
		free(s[current_pos]);
		current_pos--;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	current_pos;
	int		n;

	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (number_of_words(s, c) + 1));
	if (!split)
		return (NULL);
	split[number_of_words(s, c)] = NULL;
	n = 0;
	current_pos = 0;
	while (n < number_of_words(s, c))
	{
		if (s[current_pos] != c)
		{
			split[n] = ft_substr(s, current_pos, word_len(s, c, current_pos));
			if (!split[n])
				return (free_split(split, n));
			current_pos += word_len(s, c, current_pos);
			n++;
		}
		current_pos++;
	}
	return (split);
}
