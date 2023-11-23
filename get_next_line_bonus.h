#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1337
#endif

char	*get_next_line(int fd);
char	*ft_strdup(const char *str);
char	*ft_substr(const char *str, unsigned int start, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t len);
size_t  ft_strlen(const char *s);
void	*ft_memset(void *str, int c, size_t len);
#endif