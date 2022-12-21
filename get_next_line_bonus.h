/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:55:20 by destrada          #+#    #+#             */
/*   Updated: 2022/10/20 20:23:26 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);

int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_nextstr(char *str_rem, int line_len);
char	*ft_line(char *str_rem);
char	*ft_read(int fd, char *buff, char *str_rem);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif