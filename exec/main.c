/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:18:10 by otmallah          #+#    #+#             */
/*   Updated: 2022/03/19 18:28:05 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	built_func(char *av, char *av2, char *av3, t_mini *index)
{
	if (ft_strcmp(av, "pwd") == 0)
		ft_pwd();
	if (ft_strcmp(av, "cd") == 0)
	{
		ft_cd(av2);
		exit(0);
	}
	if (ft_strcmp(av, "echo") == 0 && ft_strcmp(av2 ,"-n") == 0)
	{
		ft_echo(av3);
	}
	if (ft_strcmp(av, "exit") == 0)
		ft_exit();
	if (ft_strcmp(av, "env") == 0)
		ft_env(index);
}

int main(int ac, char **av, char **env)
{
	t_mini index;
	char *read;
	int i;
	int a;

	i = 0;
	if (ac == 1)
	exit(0);
	index.string = env;
	built_func(av[1], av[2], av[3], &index);
	index.str = getenv("PATH");
	index.str = ft_strchr(index.str, '/');
	index.tab = ft_split(index.str, ':');
	while (index.tab[i])
	{
		a = ft_strlen(index.tab[i]);
		index.tab[i][a] = '/';
		index.tab[i][a + 1] = '\0';
	    index.str = ft_strjoin(index.tab[i], av[1]);
	    if (access(index.str, F_OK) == 0)
		{
	        execve(index.str, &av[1], env);
		}
		i++;
	}
}
