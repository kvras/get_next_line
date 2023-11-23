#include "get_next_line_bonus.h"

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

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*ptr;

	if (!dst && !src)
		return (NULL);

	i = 0;
	ptr = (unsigned char *)dst;
	while (i < len)
	{
		*ptr = *((unsigned char *)src);
		i++;
		src++;
		ptr++;
	}
	return (dst);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(str);
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ptr = (char *)ft_memcpy(ptr, str, len);
	ptr[len] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
		return (NULL);
	if (ft_strlen(str + start) < len)
		len = ft_strlen(str + start);
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (0);
	while (i < len && (str + start)[i])
	{
		ptr[i] = (str + start)[i];
		i++;
	}
	ptr[i] = '\0';
	//printf("%s", ptr);
	return (ptr);
}
