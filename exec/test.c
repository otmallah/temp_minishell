/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:50:31 by otmallah          #+#    #+#             */
/*   Updated: 2022/03/26 16:50:32 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minishell.h"

int	find(char *str)
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

int find_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
			return i;
		i++;
	}
	return 0;
}

int main(int ac, char **av, char **env)
{
	int i;
	int j;
	char *str;
	char *temp;
	char buff[100];
	int p[2];

	j = find(av[1]);
	temp = getenv("PATH");
	if (j == 1)
	{
		pipe(p);
		str = ft_substr(av[1], 0, find_len(av[1]));
		//if (fork() == 0)
		//{
		execve("/bin/ps", &str, &str);
		//}
		//wait(NULL);
		//read(0, buff, 6);
		//printf("buff %s\n", buff);
	}
}
