/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:55:34 by lloginov          #+#    #+#             */
/*   Updated: 2025/01/20 19:56:40 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdlib.h>
#include <stdio.h>

static int	count_words(const char *str, char c)
{
	int	i;
	int		mot;

	i = 0;
	mot = 0;
	while (*str)
	{
		if (*str != c && mot == 0)
		{
			mot = 1;
			i++;
		}
		else if (*str == c)
			mot = 0;
		str++;
	}
	return (i);
}

static const char	*next_wd(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == c)
		i++;
	return (&str[i]);
}

static int	world_len(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	**ft_split(const char *s, char c)
{
	int	j;
	int	word_count;
	int	i;
	int	word_len;
	char	**ptr;

	word_count = count_words(s, c);
	i = 0;
	ptr = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!ptr)
		return (NULL);
	while (*s && i < word_count)
	{
		s = next_wd(s, c);
		word_len = world_len(s, c);
		ptr[i] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!ptr[i])
			return (NULL);
		j = 0;
		while (j < word_len)
			ptr[i][j++] = *s++;
		ptr[i++][word_len] = '\0';
	}
	ptr[word_count] = NULL;
	return (ptr);
}
