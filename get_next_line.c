#include "get_next_line.h"

static size_t find_line_size(int fd, char c, size_t i, char *storage)
{
	while(c != '\n')
	{
		read(fd, &c, 1);
		storage[i] = c;
		i++;
	}

	//printf("allocated %zu bytes\n", i);
	return (i);
}


static char *read_line(int fd)
{
	char *storage;
	char tmp;
	static size_t i;
	size_t line_buffer;

	storage = NULL;
	tmp = '\0';

	line_buffer = find_line_size(fd, tmp, i, storage);

	storage = malloc(line_buffer + 1);
	if(!storage)
		return(NULL);

	if(line_buffer < BUFFER_SIZE)
		read(fd, storage, line_buffer);

	printf("%s", storage);
	return(storage);
}


char	*get_next_line(int fd)
{
	char *line;

	line = NULL;
	if(!fd || fd < 0)
		return (NULL);

	line = read_line(fd);
	if(!line)
		return (NULL);
	else
		return(line);
}



// static int read_line(int fd)
// {
// 	char *storage;
// 	char tmp[1];
// 	static size_t i;


// 	storage = malloc(BUFFER_SIZE + 1);
// 	if(!storage)
// 		return (0);
	
// 	tmp[0] = '\0';

// 	i = 0;
// 	while(i < BUFFER_SIZE)
// 	{
// 		if (read(fd, tmp, 1) < 0)
// 			return(0);
// 		if (tmp[0] == '\n')
// 		{
// 			printf("[NEW LINE DETECTED] %s\n", storage);
// 			i++;
// 			return(1);
// 		}
// 		else
// 		{
// 			storage[i] = tmp[0];
// 		}
// 		i++;
// 	}


// 	printf("[NEWLINE NOT DETECTED] 	%s\n", storage);
// 	//printf("\n\nBUFFER SIZE IS = %d\n", BUFFER_SIZE);
// 	return(1);
// }