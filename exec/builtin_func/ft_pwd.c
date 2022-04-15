/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:12:17 by otmallah          #+#    #+#             */
/*   Updated: 2022/04/14 01:01:59 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(t_parse *iterator)
{
	char	buff[256];
	int		fd;

	if (iterator->redirection)
	{
		if (iterator->redirection->type == T_RDROUT)
			fd = open(iterator->redirection->file, O_CREAT | O_RDWR , 0777);
		else if (iterator->redirection->type == T_APPEND)
			fd = open(iterator->redirection->file, O_CREAT | O_RDWR | O_APPEND , 0777);
		if (fork() == 0)
		{
			dup2(fd, STDOUT_FILENO);
			printf("%s\n" , getcwd(buff, sizeof(buff)));
			exit(0);
		}
		wait(NULL);
	}
	else
		printf("%s\n" , getcwd(buff, sizeof(buff)));
	close(fd);
}
