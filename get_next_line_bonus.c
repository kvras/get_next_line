#include "get_next_line_bonus.h"
#include <stdio.h>

int	allocation(char **buffer)
{
	char	*ptr;
	int		i;

	if (!(*buffer))
	{
		*buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!(*buffer))
			return (0);
		ft_memset(*buffer, 0, BUFFER_SIZE + 1);
	}
	else
	{
		i = 0;
		ptr = (char *)malloc(BUFFER_SIZE + ft_strlen(*buffer) + 1);
		if (!ptr)
		{
			free(*buffer);
			*buffer = NULL;
			return (0);
		}
		while ((*buffer)[i])
		{
			ptr[i] = (*buffer)[i];
			i++;
		}
		ft_memset(ptr + i, 0, BUFFER_SIZE + 1);
		free(*buffer);
		*buffer = ptr;
	}
	return (1);
}

char	*return_line(char **buffer, size_t len)
{
	char	*str;
	char	*new_buffer;
	size_t	i;

	i = ft_strlen((const char *)*buffer);
	new_buffer = NULL;
	str = ft_substr((const char *)*buffer, 0, len);
	if (!str)
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	if (len < i)
	{
		new_buffer = ft_substr((const char *)*buffer, len, i - len);
		if(!new_buffer)
		{
			free(str);
			free(*buffer);
			*buffer = NULL;
			return (NULL);	
		}
		free(*buffer);
		*buffer = new_buffer;
	}
	else
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer[10240];
	int			i;
	int 		nbr = 0;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || fd >= 10240)
	{
		if (fd >= 0 && fd < 10240 && buffer[fd])
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
		}
		return (NULL);
	}
	while (allocation(&buffer[fd]))
	{
		if ((nbr = read(fd, buffer[fd] + ft_strlen(buffer[fd]), BUFFER_SIZE)) > 0)
		{
			while (buffer[fd][i])
			{
				if (buffer[fd][i] == '\n')
					return (return_line(&buffer[fd], i + 1));
				i++;
			}
		}
		else if (nbr < 0)
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
			return (NULL);
		}
		else
			break ;
	}
	if (!buffer[fd])
		return (free(buffer[fd]), buffer[fd] = NULL, NULL); //
	i = 0;
	while (buffer[fd] && buffer[fd][i])
	{
		if (buffer[fd][i] == '\n')
			return (return_line(&buffer[fd], i + 1));
		i++;
	}
	return (return_line(&buffer[fd], i));
}
