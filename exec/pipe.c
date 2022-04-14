#include "pipe.h"

typedef	struct s_solo {
	char **string;
	char	**tab;
	char	*str;
}	t_solo;

void	find_path(char *str, t_solo *index)
{
	int i;
	int a;
	char *temp;
	char **tep;

	i = 0;
	temp = getenv("PATH");
	//printf("%s\n", temp);
	index->tab = ft_split(temp, ':');
	tep = (char **)malloc(sizeof(char *));
	tep[0] = str;
	while (index->tab[i])
	{
		a = ft_strlen(index->tab[i]);
		index->tab[i][a] = '/'; // bach tkoun lpath kamla n '/'
		index->tab[i][a + 1] = '\0'; // bach nsali string
		index->str = ft_strjoin(index->tab[i], str);
		if (access(index->str, F_OK) == 0)
		{
			execve(index->str, &tep[0], index->string);
		}
		i++;
	}

}

int main(int ac, char **av ,char **env)
{
	int fd[3][2];
	int fds;
	int status;
	char buff[256];
	char *str[] = {av[1], NULL};
	t_solo index;

	int i = 0;
	while (i < 2)
	{
		if (pipe(fd[i]) < 0)
			return 1;
		i++;
	}
	index.string = env;
	int id = fork();
	if (id == 0)
	{
		dup2(fd[0][1], STDOUT_FILENO);
		dup2(fd[0][0], STDIN_FILENO);
		find_path(av[1], &index);
	}
	dup2(fd[0][0], STDIN_FILENO);
	close(fd[0][1]);
	id = fork();
	if (id == 0)
	{
		close(fd[1][1]);
		dup2(fd[0][0], STDIN_FILENO);
		dup2(fd[1][0], 0);
		find_path(av[2], &index);
	}
	dup2(fd[1][0], STDIN_FILENO);
	close(fd[1][1]);
	id = fork();
	if (id == 0)
	{
		close(fd[2][1]);
		dup2(fd[2][0], 0);
		find_path(av[3], &index);
	}
	//wait(NULL);
	while ( wait(NULL) != -1 );
	//close(fd[1]);
	//close(fd[0]);
	//close(fds);
}