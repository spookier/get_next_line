#include "get_next_line.h"

static char *cut_newline(char *storage)
{
	int index;
	char *before_newline;
	char *after_newline;

	index = ft_strchr(storage, '\n');

	before_newline = ft_substr(storage, 0, index);
	
	after_newline = ft_substr(storage,
		(ft_strlen(storage) - ft_strlen	(before_newline)),
		ft_strlen(storage));
	storage = after_newline;
	printf("after newline: %s\n", storage);
	return(before_newline);
}

static char *read_line(int fd, char *storage, char *tmp)
{
	tmp = malloc(BUFFER_SIZE + 1);
	int	read_flag;
	int	index;
	
	index = -1;
	if(tmp == NULL)
		return (NULL);
	if (storage != NULL)
		index = ft_strchr(storage, '\n');
	while (1)
	{
		if (index >= 0)
			break ;
		read_flag = read(fd, tmp, BUFFER_SIZE);
		//printf("tmp : %s\n", tmp);
		if(read_flag < 0)
			return(NULL);
		storage = ft_strjoin(storage, tmp);
		//printf("storage : %s\n", storage);
		index = ft_strchr(storage, '\n');
	}
	
	return(cut_newline(storage));
}

char *get_next_line(int fd)
{
	static char *storage;
	char *line;

	storage = NULL;
	line = NULL;

	if (!fd || fd < 0)
		return(NULL);

	line = read_line(fd, storage, line);
	if(!line)
		return (NULL);
	else
		return (line);
}