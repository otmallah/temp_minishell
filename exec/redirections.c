/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:12:10 by otmallah          #+#    #+#             */
/*   Updated: 2022/04/09 00:14:22 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Parse/minishell_exec.h"

int find_red(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
		if (str[i] == '>' && str[i + 1] == '>')
			return 2;
        if (str[i] == '>')
            return 1;
        i++;
    }
	return 0;
}

int	find_space5(char *tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if(tab[i] == ' ')
			return 1;
		i++;
	}
	return 0;
}

int	find_path_red(t_pipe *index, t_parse *iterator, t_mini *idx)
{
	int i;
	int a;
	char *temp;
	char **tep;

	i = 0;
	ft_check_cmd(iterator, idx);
	temp = getenv("PATH");
	index->tab = ft_split(temp, ':');
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

void	ft_redirections(t_mini *index, t_idx *id, t_pipe *pipx, t_parse *iterator)
{
    int a;
	int ID_FOR;
    char **tab;
	int fd = 0;
	int out = 0;

	if (iterator->redirection)
	{
		if (iterator->redirection->type == T_RDRIN)
		{
			if (access (iterator->redirection->file, F_OK) == 0)
			{
				fd = open(iterator->redirection->file, O_CREAT, O_RDONLY, 0777);
				if (iterator->redirection->type == T_RDROUT)
					out = open(iterator->redirection->file, O_CREAT | O_RDWR , 0777);
				if (fork() == 0)
				{
					if (out != 0)
						dup2(out, STDOUT_FILENO);
					dup2(fd, STDIN_FILENO);
					find_path_red(pipx, iterator, index);
				}
				close(fd);
				close(out);
				wait(NULL);
			}
			else
			{
				write (2, "no such file or directory:", 26);
				write (2, iterator->redirection->file, ft_strlen(iterator->redirection->file));
				write(2, "\n", 1);
			}
		}
		else if (iterator->redirection->type == T_RDROUT)
		{
			fd = open(iterator->redirection->file, O_CREAT | O_RDWR , 0777);
			if (fork() == 0)
			{
				dup2(fd, STDOUT_FILENO);
				find_path_red(pipx, iterator, index);
			}
			close(fd);
			wait(NULL);
		}
		else if (iterator->redirection->type == T_APPEND)
		{
			fd = open(iterator->redirection->file , O_CREAT | O_RDWR | O_APPEND , 0777);
			if (fork() == 0)
			{
				dup2(fd, STDOUT_FILENO);
				find_path_red(pipx, iterator, index);
			}
			close(fd);
			wait(NULL);
		}
	}
	// if (str[0] == '>' && str[1] != '>')
	// {
	// 	tab = ft_split(str, '>');
	// 	fd = open(tab[0], O_CREAT | O_RDWR , 0777);
	// }
	// else if (str[0] == '>' && str[1] == '>')
	// {
	// 	tab = ft_split(str, '>');
	// 	fd = open(tab[0], O_CREAT | O_RDWR , 0777);
	// }
	// else if (find_red(str) == 2)
	// {
	// 	tab = ft_split(str, '>');
	// 	fd = open(tab[1], O_CREAT | O_RDWR | O_APPEND , 0777);
	// 	ID_FOR = fork();
	// 	if (ID_FOR == 0)
	// 	{
	// 		dup2(fd, STDOUT_FILENO);
	// 		find_path_red(tab[0], pipx, index);
	// 	}
	// 	wait(NULL);
	// 	//close(fd);
	// }
	// else
	// {
    // 	tab = ft_split(str, '>');
    //     fd = open(tab[1], O_CREAT | O_WRONLY, 0777);
	// 	ID_FOR = fork();
	// 	if (ID_FOR == 0)
	// 	{
	// 		dup2(0, STDIN_FILENO);
    //     	dup2(fd, STDOUT_FILENO);
	// 		find_path_red(tab[0], pipx, index);
	// 	}
	// 	wait(NULL);
	// 	close(fd);
	// }
}
