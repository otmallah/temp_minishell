
#include "minishell.h"

char *ft_getenv(char *str, t_mini *index);

void	built_func(char *av)
{
	//if (ft_strcmp(av, "pwd") == 0)
	//	ft_pwd();
	//if (ft_strcmp(av, "cd") == 0)
	//{
	//	ft_cd(av2);
	//}
	ft_echo(av);
	//if (ft_strcmp(av, "exit") == 0)
	//	ft_exit();
	//if (ft_strcmp(av, "env") == 0)
	//	ft_env(index);
}

int    find_space(char *str);

void	func_all(t_mini *index, char *str)
{
	int i;
	int a;
	int res;
	char **test;
	char *str2;

	i = 0;
	res = find_space(str);
	index->tab = ft_split(index->str, ':');
	if (res == 1)
		test = ft_split(str, ' ');
	else
	{
		test = (char **)malloc(sizeof(char *) * 1);
		test[0] = str;
	}
	while (index->tab[i])
	{
		a = ft_strlen(index->tab[i]);
		index->tab[i][a] = '/'; // bach tkoun lpath kamla n '/'
		index->tab[i][a + 1] = '\0'; // bach nsali string
		index->str = ft_strjoin(index->tab[i], test[0]);
		if (access(index->str, F_OK) == 0)
		{
			execve(index->str, &test[0], index->string);
		}
		i++;
	}
	printf("command not found22:%s\n", test[0]);
}

// int    find_space(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == ' ')
// 			return 1;
// 		i++;
// 	}
// 	return 2;
// }


// void    sig_handler(int signum)
// {
//     if (signum == SIGINT)
//     {
//         printf("\n");
//         rl_on_new_line();
//         rl_replace_line("", 0);
//         rl_redisplay();
//     }
// }

int main(int ac, char **av, char **env)
{
	t_mini index;
	t_idx id;
	char *str;
	int a = 0;
	char **tmp;
	int	space;
	t_pipe pipe;

	index.count2 = 0;
	index.finde = NULL;
	index.tab_exp = env;
	index.string = env;
	index.tab_unset = env;
	id.c = 0;
	id.cnt = 0;
	id.a = 0;
	id.b = 0;
	id.d = 0;
	id.poor = 1;
	id.cot = 0;
	index.
	// signal(SIGINT, sigint_handler);
	// while (1)
	// {
	// 	str = readline("minishell >$ ");
	// 	if (str)
	// 	{
	// 		add_history(str);
	// 		check_pipe(&pipe, &index, &id, str);
	// 		if (str[0] == '<' && str[1] == '<')
	// 			ft_heredoce(&index, &id, &pipe, str);
	// 		else
	// 			ft_redirections(&index, &id, &pipe, str);
	// 		a = find_space(str);
	// 		if (a == 1)
	// 		{
	// 			pipe.tab = ft_split(str, ' ');
	// 			space = 1;
	// 		}
	// 		else
	// 		{
	// 			pipe.tab = (char **)malloc(sizeof(char *));
	// 			pipe.tab[0] = str;
	// 			space = 0;
	// 		}
	// 		if (ft_strcmp(pipe.tab[0] , "echo") == 0  && ft_strcmp(pipe.tab[1] , "-n") == 0)
	// 			built_func(pipe.tab[2]);
	// 		else if (ft_strcmp(pipe.tab[0], "env") == 0)
	// 			ft_env(&index, &id);
	// 		else if (ft_strcmp(pipe.tab[0], "pwd") == 0)
	// 			ft_pwd();
	// 		else if (ft_strcmp(pipe.tab[0], "cd") == 0)
	// 		{
	// 			if (space == 1)
	// 			{
	// 				ft_cd(pipe.tab[1]);
	// 			}
	// 		}
	// 		else if (ft_strcmp(pipe.tab[0], "export") == 0)
	// 	   	{
	// 			if (a == 1)
	// 	   			ft_export(&index, &id, pipe.tab[1]);
	// 			else
	// 			   ft_export(&index, &id, NULL);
	// 		}
	// 		else if (ft_strcmp(pipe.tab[0], "exit") == 0)
	// 			ft_exit(&index);
	// 		else if (ft_strcmp(pipe.tab[0], "unset") == 0)
	// 		{
	// 			ft_unset(&index, &id, pipe.tab[1]);
	// 		}
	// 		else
	// 		{
	// 			if (fork() == 0) // hna dert l fork bach n3ty child executy li cmd o ikhali main proc khedam
	// 			{
	// 				index.str = ft_getenv("PATH", &index);
	// 				if (index.str == NULL)
	// 					printf("command not found:%s\n", pipe.tab[0]);
	// 				else
	// 				{
	// 					//index.tab = ft_split(index.str, ':');
	// 					func_all(&id, &index, str);
	// 				}
	// 			}
	// 			wait(NULL); // hadi bach itsana hta isali childe 3ad i trunna parent
	// 		}
	// 	}
	// }
}

