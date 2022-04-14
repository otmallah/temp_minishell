/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:35:39 by otmallah          #+#    #+#             */
/*   Updated: 2022/04/12 23:11:35 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int find_heredoc(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '<' && str[1] == '<')
			return 1;
		else if (str[i] == '<' && str[i + 1] == '<')
			return 2;
		i++;
	}
	return 0;
}

int findred(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
		if (str[i] == '>' && str[i + 1] == '>')
			return 1;
		else if (str[i] == '>' && str[i + 1] != '>')
			return 2;
        i++;
    }
	return 0;
}

int	tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return i;
}

int	open_mult_file(char *str)
{
	int i;
	char **tab;
	int	fd;

	i = 0;
	tab = ft_split(str, '>');
	while (tab[i])
	{
		if (tab[i + 1] != NULL)
			open(tab[i], O_CREAT | O_RDWR , 0777);
		else if (tab[i + 1] == NULL)
		{
			fd = open(tab[i], O_CREAT | O_RDWR , 0777);
			return fd;
		}
		i++;
	}
	return 0;
}

// void	exec_cmd_first(t_mini *index, t_pipe *pipx, char *str)
// {
// 	char	*str_readline;
// 	char *str2;
// 	char	**tab;

// 	str2 = ft_strchr(str, '<');
// 	tab = ft_split(str2, '<')
// 	int fd = open("he", )
// 	while (1)
// 	{
// 		str_readline = readline(">");
// 		if (ft_strcmp(str_readline, tab[0]) == 0)
// 			break ;
		
// 	}
// }

void    ft_heredoce(t_mini *index, t_idx *id, t_pipe *pipx, char *str)
{
	int sec_fd;
	char	**tab;
	char	*str_read;
	int fd;
	int size = 0;
	int a;

		if (findred(str) == 2)
			size = open_mult_file(ft_strchr(str, '>'));
		tab = ft_split(str, ' ');
		sec_fd = open("he", O_CREAT | O_WRONLY , 0777);
		// if (findred(str) == 1)
		// 	fd = open(tab[size - 1], O_CREAT | O_RDWR | O_APPEND , 0777);
		// else
		// 	fd = open(tab[size - 1], O_CREAT | O_RDWR , 0777);
		while (1)
		{
			str_read = readline(">");
			if (ft_strcmp(tab[0], "<<") != 0)
			{
				if (strcmp(str_read, tab[2]) == 0)
					break ;
			}
			else
			{
				if (strcmp(str_read, tab[1]) == 0)
					break ;
			}
			write(sec_fd, str_read, strlen(str_read));
			write(sec_fd, "\n", 1);
		}
		close(sec_fd);
		sec_fd = open("he",  O_RDONLY);
		if (fork() == 0)
		{
			dup2(sec_fd, STDIN_FILENO);
			if (size != 0)
				dup2(size, STDOUT_FILENO);
			if (ft_strcmp(tab[0], "<<") != 0)
				find_path_red(tab[0], pipx, index);
			else
				find_path_red(tab[2], pipx, index);
		}
		close(fd);
		close(sec_fd);
		close(size);
		wait(NULL);
}
