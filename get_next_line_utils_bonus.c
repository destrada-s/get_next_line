/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:08:29 by destrada          #+#    #+#             */
/*   Updated: 2022/10/20 20:24:00 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;

	i = 0;
	if (dstsize > 0)
	{
		while ((i < dstsize - 1) && (src[i] != '\0'))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = dstlen;
	j = 0;
	if (dstlen < dstsize - 1 && dstsize > 0)
	{
		while (src[j] != '\0' && (dstlen + j) < (dstsize - 1))
		{
		dst[i + j] = src[j];
		j++;
		}
		dst[i + j] = '\0';
	}
	if (dstlen >= dstsize)
		dstlen = dstsize;
	return (dstlen + srclen);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strjoin;
	int		lenjoin;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	lenjoin = ft_strlen(s1) + ft_strlen(s2);
	if (lenjoin == 0)
		return (free(s1), NULL);
	strjoin = (char *)malloc(lenjoin + 1 * sizeof(char));
	if (!strjoin)
	{
		free(strjoin);
		return (free(s1), NULL);
	}
	ft_strlcpy(strjoin, s1, lenjoin + 1);
	ft_strlcat(strjoin, s2, lenjoin + 1);
	free(s1);
	return (strjoin);
}
