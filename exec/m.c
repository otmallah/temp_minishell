#include "minishell.h"

int main (int ac, char **av)
{
	int fd;
	char buff[200];

	fd = open("/dev/random", O_RDWR);
	write (fd, "hana\n", 5);
	//read (fd, buff, 10);
	printf("%s", buff);
}