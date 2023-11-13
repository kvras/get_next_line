/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:41:05 by miguiji           #+#    #+#             */
/*   Updated: 2023/11/13 17:41:57 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	f(char **b)
{
	char	*ptr;
	int		i;

	if (!(*b))
		*b = (char *)malloc(BUFFER_SIZE + 1);
	else
	{
		i = 0;
		ptr = (char *)malloc(BUFFER_SIZE + ft_strlen(*b) + 1);
		while (*b[i])
		{
			ptr[i] = *b[i];
			i++;
		}
		free(*b);
		*b = ptr;
	}
	if(*b)
		return (1);
	return (0);
}

char	*line(char *b, int start, int len)
{
	char	*str;
	char	*ptr;

	str = ft_substr(b, start, len + 1);
	ptr = ft_substr(b, len, ft_strlen(b + len));
	free(b);
	b = ptr;
	return (str);
}

char	*get_next_line(int fd)
{
	int			i;
	static char	*b;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	i = 0;
	while (f(&b) && read(fd, b + i, BUFFER_SIZE) == BUFFER_SIZE)
	{
		i = 0;
		while (b[i])
		{
			if (b[i] == '\n')
				return (line(b, 0, i + 1));
			i++;
		}
	}
	i = ft_strlen((const char *)b) - 1;
	if (b[0])
		return (line(b, 0, i + 1));
	return (NULL);
}
