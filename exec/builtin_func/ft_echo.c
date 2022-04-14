/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:11:23 by otmallah          #+#    #+#             */
/*   Updated: 2022/04/14 01:18:28 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(t_parse *iteratore)
{
	int i;
	i = 2;
	int fd;
	//char *find;

	if (iteratore->redirection)
	{
		fd = open(iteratore->redirection->file, O_CREAT | O_RDWR , 0777);
		if (fork() == 0)
		{
			dup2(fd, STDOUT_FILENO);
			while(iteratore->args[i])
			{
				printf("%s ", iteratore->args[i]);
				i++;
			}
			exit(0);
		}
		wait(NULL);
	}
	else
	{
		while(iteratore->args[i])
		{
			printf("%s ", iteratore->args[i]);
			i++;
		}
	}
}
