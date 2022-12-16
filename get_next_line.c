#include "get_next_line.h"

static int read_line(int fd)
{
	char *storage;
	char tmp[1];
	size_t i;


	storage = malloc(BUFFER_SIZE + 1);
	if(!storage)
		return (0);
	
	tmp[0] = '\0';

	i = 0;
	while(i < BUFFER_SIZE)
	{
		if (read(fd, tmp, 1) < 0)
			return(0);
		
		if (tmp[0] == '\n')
		{
			printf("new line\n");
			printf("%s_\n", storage);

			return(1);

		}
		else
			storage[i] = tmp[0];
		i++;
	}


	printf("%s\n", storage);
	printf("\n\nBUFFER SIZE IS = %d\n", BUFFER_SIZE);
	return(1);
}

char	*get_next_line(int fd)
{
	if(!fd || fd < 0)
		return (NULL);
	if(!read_line(fd))
		return (NULL);

	return(0);
}
