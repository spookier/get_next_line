/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:27:30 by acostin           #+#    #+#             */
/*   Updated: 2023/03/20 15:34:56 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(int fd, char *storage)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (ft_strchr(storage, '\n') == 0 && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage[256];

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return (0);
	storage[fd] = read_line(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = get_line(storage[fd]);
	storage[fd] = new_storage(storage[fd]);
	return (line);
}
