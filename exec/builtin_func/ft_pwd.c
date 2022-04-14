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
		fd = open(iterator->redirection->file, O_CREAT | O_RDWR , 0777);
		if (iterator->redirection->type == T_RDROUT)
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
