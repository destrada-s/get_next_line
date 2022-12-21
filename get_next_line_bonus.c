/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:46:00 by destrada          #+#    #+#             */
/*   Updated: 2022/10/21 12:29:09 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *buff, char *str_rem)
{
	int		i;
	ssize_t	size_read;

	i = 0;
	size_read = read(fd, buff, BUFFER_SIZE);
	if (size_read == -1)
		return (free(buff), free(str_rem), NULL);
	buff[size_read] = '\0';
	while (buff[i] != '\n' && buff[i] != '\0' && size_read != 0)
	{
		if (i == BUFFER_SIZE - 1)
		{
			i = -1;
			str_rem = ft_strjoin(str_rem, buff);
			size_read = read(fd, buff, BUFFER_SIZE);
			if (size_read == -1)
				return (free(buff), free(str_rem), NULL);
			buff[size_read] = '\0';
		}
	i++;
	}
	if (buff[i] == '\n' || buff[i] == '\0')
		str_rem = ft_strjoin(str_rem, buff);
	return (free(buff), str_rem);
}

char	*ft_line(char *str_rem)
{
	char	*line;
	size_t	i;

	i = 0;
	while (str_rem[i] != '\n' && str_rem[i] != '\0')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
	{
		free(line);
		return (0);
	}
	i = 0;
	while (str_rem[i] != '\n' && str_rem[i] != '\0')
	{
		line[i] = str_rem[i];
		i++;
	}
	if (str_rem[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_nextstr(char *str_rem, int line_len)
{
	char	*newstr_rem;
	int		str_rem_len;
	int		i;

	i = 0;
	str_rem_len = ft_strlen(str_rem);
	if (str_rem_len == line_len)
	{
		free(str_rem);
		return (NULL);
	}
	newstr_rem = (char *)malloc((str_rem_len - line_len + 1) * sizeof(char));
	if (!newstr_rem)
	{
		free(newstr_rem);
		return (0);
	}
	while (str_rem[line_len + i] != '\0')
	{
		newstr_rem[i] = str_rem[line_len + i];
		i++;
	}
	newstr_rem[i] = '\0';
	free(str_rem);
	return (newstr_rem);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*str_rem[4096];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = NULL;
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	str_rem[fd] = ft_read(fd, buff, str_rem[fd]);
	if (str_rem[fd] == NULL)
		return (NULL);
	line = ft_line(str_rem[fd]);
	str_rem[fd] = ft_nextstr(str_rem[fd], ft_strlen(line));
	return (line);
}
