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

static int	f(char **b)
{
	char	*ptr;
	int		i;

	if (!(*b))
	{
		*b = (char *)malloc(BUFFER_SIZE + 1);
		bzero(*b, BUFFER_SIZE);
	}
	else
	{
		i = 0;
		ptr = (char *)malloc(BUFFER_SIZE + ft_strlen(*b) + 1);
		while ((*b)[i])
		{
			ptr[i] = (*b)[i];
			i++;
		}
		bzero(ptr + i, BUFFER_SIZE);
		free(*b);
		*b = ptr;
	}
	if (*b)
		return (1);
	return (0);
}

static char	*line(char **b, int start, int len)
{
	char	*str;
	char	*ptr;

	ptr = NULL;
	str = ft_substr(*b, start, len);
	if (len < ft_strlen(*b))
		ptr = ft_substr(*b, len, ft_strlen(*b + len));
	free(*b);
	*b = ptr;
	return (str);
}

char	*get_next_line(int fd)
{
	int			i;
	static char	*b;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	i = (b && *b) ? ft_strlen(b) : 0;
	while (f(&b) && read(fd, b + i, BUFFER_SIZE) > 0)
	{
		b[ft_strlen(b)] = '\0';
		i = 0;
		while (b[i])
		{
			if (b[i] == '\n')
				return (line(&b, 0, i + 1));
			i++;
		}
	}
	if (b && *b)
	{
		i = ft_strlen(b) - 1;
		return (line(&b, 0, i + 1));
	}
	return (NULL);
}