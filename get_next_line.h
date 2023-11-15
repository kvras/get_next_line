/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:44:24 by miguiji           #+#    #+#             */
/*   Updated: 2023/11/14 09:44:29 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#define BUFFER_SIZE 2

char	*ft_strdup(const char *str);
char	*ft_substr(const char *str, unsigned int start, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t len);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);

#endif
