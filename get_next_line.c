#include "get_next_line.h"

// static size_t find_line_size(int fd)
// {
// 	size_t i;
// 	size_t bytes_read;
// 	char temp[BUFFER_SIZE];
	
// 	//i = 0;
// 	// if(*arr == NULL)
// 	// {

// 	// // }
// 	// while (strchr() != 0)
// 	// {
// 	// 	bytes_read = read(fd, temp, BUFFER_SIZE);
// 	// 	i++;
// 	// }
// 	printf("line size is %zu bytes\n", i);
// 	return(i);
// }


static void init_arr(int fd, char *arr)
{
	arr = malloc(BUFFER_SIZE + 1);
}

static void fill_arr(int fd, char *arr)
{
	size_t i;

	i = 0;
	read(fd, arr, BUFFER_SIZE);
	if()
	{

	}

}

static char *read_line(int fd, char *arr)
{

	// for first call of GNL
	if(arr == NULL)
	{
		init_arr(fd, arr);
		fill_arr(fd, arr);
	}
	else
		printf("arr full\n");

	return(arr);
}


char	*get_next_line(int fd)
{
	char *line;
	char *arr;
	
	arr = NULL;
	line = NULL;

	if(!fd || fd < 0)
		return (NULL);

	line = read_line(fd, arr);
	if(!line)
		return (NULL);
	else
		return(line);
}


// static size_t find_line_size(int fd, char c, size_t i, char *storage)
// {
// 	while(c != '\n')
// 	{
// 		read(fd, &c, 1);
// 		storage[i] = c;
// 		i++;
// 	}

// 	//printf("allocated %zu bytes\n", i);
// 	return (i);
// }


// static char *read_line(int fd)
// {
// 	char *storage;
// 	char tmp;
// 	static size_t i;
// 	size_t line_buffer;

// 	storage = NULL;
// 	tmp = '\0';

// 	line_buffer = find_line_size(fd, tmp, i, storage);

// 	storage = malloc(line_buffer + 1);
// 	if(!storage)
// 		return(NULL);

// 	if(line_buffer < BUFFER_SIZE)
// 		read(fd, storage, line_buffer);

// 	printf("%s", storage);
// 	return(storage);
// }



// ------------------------

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