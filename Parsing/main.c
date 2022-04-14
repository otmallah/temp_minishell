/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:53:58 by zmeribaa          #+#    #+#             */
/*   Updated: 2022/04/14 01:24:19 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    find_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return 1;
		i++;
	}
	return 2;
}

void	func_all(t_mini *index, t_parse *iterator)
{
	int i;
	int a;
	char **test;
	char *str2;

	i = 0;
	index->tab = ft_split(index->str, ':');
	while (index->tab[i])
	{
		a = ft_strlen(index->tab[i]);
		index->tab[i][a] = '/'; // bach tkoun lpath kamla n '/'
		index->tab[i][a + 1] = '\0'; // bach nsali string
		index->str = ft_strjoin(index->tab[i], iterator->cmd);
		if (access(index->str, F_OK) == 0)
		{
			execve(index->str, &iterator->args[0], index->string);
		}
		i++;
	}
	write (2, "command not found:", 18);
	write (2, iterator->cmd, ft_strlen(iterator->cmd));
	write(2, "\n", 1);
	exit(0);
}

int		find_pipe(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
			return 1;
		i++;
	}
	return 0;
}

// int poor(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '<' && str[i + 1] == '<')
// 			return 1;
// 		else if (str[i] == '>')
// 			return 2;
// 		else if (str[i] == '<' && str[i + 1] != '<')
// 			return 3;
// 		i++;
// 	}
// }

void	check_pipe(t_pipe *pipe, t_mini *index, t_parse *iterator, char *str)
{
	int a;

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
			ft_pwd();
		else if (ft_strcmp(iterator->cmd, "env") == 0 && ft_strcmp(iterator->args[1], "-n") == 0)
			ft_env(index, id);
		else if (ft_strcmp(iterator->cmd, "echo") == 0)
			ft_echo(iterator);
		else if (ft_strcmp(iterator->cmd, "cd") == 0)
			ft_cd(iterator->args[1]);
		else
			check_pipe(pipx, index, iterator, iterator->cmd);
	}
	else
	{
		ft_pipe(index, pipx, iterator);
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
		// 	i = 0;
		// 	while (iterator->args[i])
		// 	{
		// 		printf(" \t the args is %s\n", iterator->args[i]);
		// 		i++;
		// 	}
		// 	iterator = iterator->next;
		// }
		//ft_export(&index, &id, NULL);
		if (mini.line[0])
			ft_check_line(&index, &pipe, iterator, &id, env);
	}
	return (0);
}