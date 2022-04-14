/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 10:35:35 by otmallah          #+#    #+#             */
/*   Updated: 2022/04/02 10:35:36 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
int	find_len(char **tab)
{
	int i;
	i = 0;
	while (tab[i])
		i++;
	return i;
}
int main(int ac, char **av ,char **env)
{
	int fds;
	int a;
	int i;
	int id;
	char **tab;
	char *str[] = {av[1], NULL};
	t_solo index;
	index.string = env;
	tab = ft_split(av[1], '|');
	a = find_len(tab);
	int fd[a][2];
	i = 0;
	while (i < a - 1)
	{
		if (pipe(fd[i]) == -1)
			return 1;
		i++;
	}
	i = 0;

	int k = dup(1);
	while (i < a)
	{
		if (i == 0)
		{
			id = fork();
			if (id == 0)
			{
				if(dup2(fd[i][1], 1) < 0)
					write(1, "aja", 3);
				write(1, "uuu", 3);
				find_path(tab[i], &index);
			}
			else
			{
				printf("ii\n");
				dup2(fd[i][0], STDIN_FILENO);	
			}
			wait(NULL);
		}
		else if (i == (a - 1))
		{
			id = fork();
			if (id == 0)
			{
				dup2(STDOUT_FILENO, k);
				find_path(tab[i], &index);
			}
			printf("kk\n");
			wait(NULL);
		}
		else
		{
			id = fork();
			if (id == 0)
			{
				close(fd[i][0]);
				dup2(fd[i][1], k);
				find_path(tab[i], &index);
			}
			else
				dup2(fd[i][0], 0);
			printf("pp\n");
			wait(NULL);
		}
		i++;
	}
	i = 0;
	while (i <= a)
	{
		close(fd[i][1]);
		close(fd[i][0]);
		i++;
	}
	//close(fd[i][1]);
	//close(fd[i][0]);
}

//int main()
//{
//    int fd = open("file.txt", O_WRONLY);
//    write(fd,"lolo",4);
//}