#include "get_next_line.h"

static char *cut_newline(char **storage)
{
	int index;
	char *before_newline;
	char *after_newline;

	after_newline = NULL;
	before_newline = NULL;
	index = ft_strchr(*storage, '\n');

	before_newline = ft_substr(*storage, 0, index + 1);

	after_newline = ft_substr((*storage), ft_strlen(before_newline), ft_strlen(*storage));
	*storage = after_newline;

	return (before_newline);
}

static char *read_line(int fd, char **storage, char *tmp)
{
	tmp = malloc(BUFFER_SIZE + 1);
	int	read_flag;
	int	index;
	
	index = -1;
	if(tmp == NULL)
		return (NULL);
	if (*storage != NULL)
		index = ft_strchr(*storage, '\n');
	while (1)
	{
		if (index >= 0)
			break ;
		read_flag = read(fd, tmp, BUFFER_SIZE);
		if(read_flag < 0)
			return(NULL);
			//printf("will add %s ++ %s\n\n", *storage, tmp);
		*storage = ft_strjoin(*storage, tmp);
		index = ft_strchr(*storage, '\n');
	}
	return(cut_newline(storage));
}

char *get_next_line(int fd)
{
	static char *storage;
	char *line;

	line = NULL;

	if (!fd || fd < 0)
		return(NULL);

	line = read_line(fd, &storage, line);
	
	if(!line)
		return (NULL);
	else
	{
		//printf("static: %s_\n", storage);
		return (line);
	}
}