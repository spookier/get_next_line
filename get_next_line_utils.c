#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*final_str;

	size = 1 + ft_strlen(s1) + ft_strlen(s2);
	final_str = (char *)malloc(size * sizeof(char));
	if (!final_str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		final_str[i] = s1[i];
		i++;
	}	
	j = 0;
	while (s2 && s2[j])
	{
		final_str[i++] = s2[j++];
	}
	return (final_str);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*tab;

	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
	{
		tab = malloc(1);
		if (!tab)
			return (NULL);
		tab[0] = 0;
		return (tab);
	}
	if (len > (ft_strlen(str) - start))
		tab = (char *)malloc(ft_strlen(str) - start + 1);
	else
		tab = (char *)malloc(len + 1);
	if (!tab)
		return (NULL);
	ft_strlcpy(tab, str + start, len + 1);
	return (tab);
}