#include "pipe.h"

typedef	struct s_solo {
	char **string;
	char	**tab;
	char	*str;
}	t_solo;


int	find_len(char **tab)
{
	int i;
	i = 0;
	while (tab[i])
		i++;
	return i;
}

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
			puts("hana hh");
			execve(index->str, &tep[0], index->string);
		}
		i++;
	}
}

//void    close_pipe(int in, int out, int *fd[2], int size)
//{
//	int i;
//
//	i = 0;
//	while (i < (size - 1))
//	{
//		if (fd[i])
//	}
//}

int main(int ac, char **av, char **env)
{
	int i;
	int a;
	int id;
	int res = 0;
	char **tab;
	t_solo index;

	index.string = env;
	i = 0;
	tab = ft_split(av[1], '|');
	a = find_len(tab);
	int fd[a][2];
	while (i < (a - 1))
	{
		if (pipe(fd[i]) == -1)
			return 1;
		i++;
	}
	i = 0;
	while (i < (a - 1))
	{
		if (i == 0)
		{
			id = fork();
			if (id == 0)
			{
				dup2(fd[i][1], STDOUT_FILENO);
				find_path(tab[i], &index);
			}
			dup2(fd[i][0], 0);
			wait(NULL);
		}
		else
		{
			id = fork();
			if (id == 0)
			{
				puts("*-*-*-*-*-");
				dup2(fd[i][0], 0);
				dup2(1, 1);
				find_path(tab[i], &index);
			}
			wait(NULL);
		}
		i++;
	}
	//while (wait(NULL) != -1)
	//i = 0;
	//while (i < (a - 1 * 2) )
	//{
	//	close(fd[i]);
	//	i++;
	//}
}