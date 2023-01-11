/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:36:43 by acostin           #+#    #+#             */
/*   Updated: 2023/01/11 13:42:43 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *backup, char *buf)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	if (!backup)
	{
		backup = (char *)malloc(sizeof(char) * 1);
		backup[0] = '\0';
	}
	if (!backup || !buf)
		return (NULL);
	new_str = malloc(sizeof(char) * ((ft_strlen(backup) + ft_strlen(buf))
				+ 1));
	if (new_str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (backup)
		while (backup[++i] != '\0')
			new_str[i] = backup[i];
	while (buf[j] != '\0')
		new_str[i++] = buf[j++];
	new_str[ft_strlen(backup) + ft_strlen(buf)] = '\0';
	free(backup);
	return (new_str);
}

char	*get_line(char *storage)
{
	int		i;
	char	*line_to_read;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	line_to_read = (char *)malloc(sizeof(char) * (i + 2));
	if (!line_to_read)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line_to_read[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		line_to_read[i] = storage[i];
		i++;
	}
	line_to_read[i] = '\0';
	return (line_to_read);
}

char	*new_storage(char *storage)
{
	int		i;
	int		j;
	char	*new_storage;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	new_storage = (char *)malloc(sizeof(char) * (ft_strlen(storage) - i + 1));
	if (!storage)
		return (NULL);
	i++;
	j = 0;
	while (storage[i])
		new_storage[j++] = storage[i++];
	new_storage[j] = '\0';
	free(storage);
	return (new_storage);
}
