/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:20:19 by lloginov          #+#    #+#             */
/*   Updated: 2025/01/20 19:52:46 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	ft_strlcaca(char *dest, const char *src, int destsize)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(src);
	if (dest == NULL || src == NULL)
		return (0);
	if (destsize != 0)
	{
		while (src[i] != '\0' && i < (destsize - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (size);
}

char	*ft_strjoin( char *s1,  char *s2)
{
	char	*result;
	int	len_s1;
	int	len_s2;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!result)
		return (NULL);
	ft_strlcaca(result, s1, len_s1 + len_s2 + 1);
	ft_strlcaca(result + len_s1, s2, len_s2 + 1);
	return (result);
}