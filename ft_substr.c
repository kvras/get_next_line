/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:46:01 by miguiji           #+#    #+#             */
/*   Updated: 2023/11/10 23:45:23 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
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
	return (ptr);
}

// int main()
// {
// 	char *ptr;
// 	ptr = ft_substr("hola", 0, 18446744073709551615);
// 	ptr = ft_substr("hola", 0, 18446744073709551615);
// 	printf("%s", ptr);
// 	free(ptr);
// }