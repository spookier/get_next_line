#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>


//delete this
#include <stdio.h>
//


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif


char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strchr(const char *str, int c);
char	*ft_substr(char const *str, unsigned int start, size_t len);


#endif