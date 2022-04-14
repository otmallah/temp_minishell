
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void    handler(int sig)
{
    int a ;
   // int fd = 0;

    printf("%d \n", sig);
    if (sig == SIGQUIT)
    {
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        exit(0);
    }
    if (sig == SIGINT)
    {
        puts("howa");
    }
}

int main()
{
    signal(SIGQUIT, handler);
    signal(SIGINT, handler);
    while (1)
        sleep(1);
}