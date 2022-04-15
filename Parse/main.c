/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:53:58 by zmeribaa          #+#    #+#             */
/*   Updated: 2022/04/14 01:50:50 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    find_slash(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return 1;
		i++;
	}
	return 2;
}

void	ft_check_cmd(t_parse *iterator, t_mini *index)
{
	if (iterator->cmd[0] == '.')
	{
		if (access(iterator->cmd, F_OK | X_OK) == 0)
		{
			execve(iterator->cmd, &iterator->args[0], index->string);
		}
		write (2, "minishell :no such file or directory ", 37);
		write (2, iterator->cmd, ft_strlen(iterator->cmd));
		write(2, "\n", 1);
		exit(0);
	}
	else if (find_slash(iterator->cmd) == 1)
	{
		if (access(iterator->cmd, F_OK) == 0)
		{
			execve(iterator->cmd, &iterator->args[0], index->string);
		}
	}
}

void	func_all(t_mini *index, t_parse *iterator)
{
	int i;
	int a;
	char **test;
	char *str2;

	i = 0;
	ft_check_cmd(iterator, index);
	index->tab = ft_split(index->str, ':');
	while (index->tab[i])
	{
		a = ft_strlen(index->tab[i]);
		index->tab[i][a] = '/'; // bach tkoun lpath kamla n '/'
		index->tab[i][a + 1] = '\0'; // bach nsali string
		index->str = ft_strjoin(index->tab[i], iterator->cmd);
		if (access(index->str, F_OK) == 0)
		{
			status_last_exec = 0;
			execve(index->str, &iterator->args[0], index->string);
		}
		i++;
	}
	write (2, "command not found:", 18);
	write (2, iterator->cmd, ft_strlen(iterator->cmd));
	write(2, "\n", 1);
	status_last_exec = 1;
	exit(0);
}

void	check_pipe(t_pipe *pipe, t_mini *index, t_parse *iterator, char *str)
{
	if (fork() == 0)
	{
		index->str = getenv("PATH");
		func_all(index, iterator);
	}
	wait(NULL);
}

int 	nbr_of_cmds(t_parse *head)
{
	int i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void	ft_check_line(t_mini *index, t_pipe *pipx, t_parse *iterator, t_idx *id, char **env)
{
	if (nbr_of_cmds(iterator) == 1)
	{
		if (ft_strcmp(iterator->cmd, "pwd") == 0)
			ft_pwd(iterator);
		else if (ft_strcmp(iterator->cmd, "echo") == 0 
			&& ft_strcmp(iterator->args[1], "-n") == 0)
			ft_echo(iterator);
		else if (ft_strcmp(iterator->cmd, "cd") == 0)
			ft_cd(iterator->args[1]);
		else if (ft_strcmp(iterator->cmd, "env") == 0)
			ft_env(index, id);
		else if (ft_strcmp(iterator->cmd, "exit") == 0)
			ft_exit(index);
		else
		{
			if (iterator->redirection)
			{
				while (iterator->redirection)
				{
					if (iterator->redirection->type == T_HEREDOC)
					{
						ft_heredoce(index, id, pipx, iterator);
					}
					else
						ft_redirections(index, id, pipx, iterator);
					iterator->redirection = iterator->redirection->next;
				}
			}
			else
				check_pipe(pipx, index, iterator, iterator->cmd);
		}
	}
	else
	{
		ft_pipe(index, pipx, id, iterator);
	}
}


int main(int ac, char **av, char **env)
{
	t_token *token;
	t_parse *rdr;
	t_mini index;
	t_idx id;
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
	int i = 0;
	while (1)
	{
		mini.line = readline("MINISHELL 🥵: ");
		if (mini.line == NULL)
		{
			ft_putstr_fd("exit\n", 1);
			exit(0);
		}
		if (mini.line == '\0')
			continue ;
		add_history(mini.line);
		parse();
		t_parse *iterator = mini.command;
		// while (iterator)
		// {
		// 	printf("the command is %s\n", iterator->cmd);
		// 	//printf("type %d \n", iterator->redirection->type);
		// 	i = 0;
		// 	while (iterator->args[i])
		// 	{
		// 		printf(" \t the args is %s\n", iterator->args[i]);
		// 		if (iterator->redirection->file)
		// 		{
		// 			puts("hana");
		// 			while (iterator->redirection)
		// 			{
		// 				printf("file %s \n" ,iterator->redirection->file);
		// 				iterator->redirection = iterator->redirection->next;
		// 			}
		// 		}
		// 		printf("a = %d\n", i);
		// 		i++;
		// 	}
		// 	iterator = iterator->next;
		// }
		// iterator = mini.command;
		// while (iterator->redirection)
		// {
		// 	printf("type = %d \n" ,iterator->redirection->type);
		// 	printf("file = %s \n" ,iterator->redirection->file); 
		// 	iterator->redirection = iterator->redirection->next;
		// }
		//ft_export(&index, &id, NULL);
		if (iterator->cmd)
		 	ft_check_line(&index, &pipe, iterator, &id, env);
	}
	return (0);
}
