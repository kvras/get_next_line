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

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			i;
	void			*str2;

	i = 0;
	str2 = str;
	while (i < len)
	{
		*((char *)str2) = c;
		str2++;
		i++;
	}
	return (str);
}

int	f(char **b)
{
	char	*ptr;
	int		i;

	if (!(*b))
	{
		*b = (char *)malloc(BUFFER_SIZE + 1);
		if(!(*b))
			return (0);
		ft_memset(*b, 0, BUFFER_SIZE + 1);
	}
	else
	{
		i = 0;
		ptr = (char *)malloc(BUFFER_SIZE + ft_strlen(*b) + 1);
		if (!ptr)
		{
			free(*b);
			*b = NULL;
			return (0);
		}
		while ((*b)[i])
		{
			ptr[i] = (*b)[i];
			i++;
		}
		ft_memset(ptr + i, 0, BUFFER_SIZE + 1);
		free(*b);
		*b = ptr;
	}
	if (*b)
		return (1);
	return (0);
}

char	*line(char **b, int start, size_t len)
{
	char	*str;
	char	*ptr;

	str = ft_substr(*b, start, len);
	if (!str)
	{
		free(*b);
		*b = NULL;
		return (NULL);
	}
	if (len < ft_strlen(*b))
	{
		ptr = ft_substr(*b, len, ft_strlen(*b + len));
		if (!ptr)
		{
					free(*b);
		*b = NULL;
			free(str);
			return (NULL);
		}
		free(*b);
		*b = ptr;
	}
	else
	{
		free(*b);
		*b = NULL;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	int			i;
	static char	*b = NULL;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	i = b ? ft_strlen(b) : 0;
	int readV = 0;
	while (f(&b) && (readV = read(fd, b + i, BUFFER_SIZE)))
	{
		if (readV < 0)
		{
			free(b);
			b = NULL;
			break ;
		}
		i = 0;
		while (b[i])
		{
			if (b[i] == '\n')
				return (line(&b, 0, i + 1));
			i++;
		}
	}
	if (b)
	{
		i = 0;
		while (b[i])
		{
			if (b[i] == '\n')
				return (line(&b, 0, i + 1));
			i++;
		}
		i = ft_strlen(b) - 1;
		return (line(&b, 0, i + 1));
	}
	free(b);
	return (NULL);
}
