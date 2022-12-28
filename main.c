#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	char *line;
	fd = open("test.txt", O_RDONLY);
	
	printf("RESULT=%s__\n", get_next_line(fd));
	printf("\n");
	printf("RESULT=%s__\n", get_next_line(fd));

	close(fd);

}
