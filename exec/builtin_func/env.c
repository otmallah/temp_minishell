/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:08:26 by otmallah          #+#    #+#             */
/*   Updated: 2022/04/14 00:46:51 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print2(char **tab, t_idx *idx)
{
	int i;
	int a;

	i = 0;
	a = idx->a;
	while(a >= 0)
	{
		printf("%s\n" , tab[i]);
		i++;
		a--;
	}
}

int tablen1(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return i;
}

void    ft_env(t_mini *index, t_idx *id)
{
	int i = 0;
	int a = 0;
	int j = 0;
	char	**tab;
	char **temp;

	puts("*-*-*-");
	// printf("%s \n", index->string[0]);
	a = tablen1(index->string) - id->poor;
	printf("a == %d \n", a);
	// while (a > 0)
	// {
	// 	printf("%s\n", index->string[i]);
	// 	i++;
	// 	a--;
	// }
	// if (index->env_tab)
	// 	ft_print2(index->env_tab, id);
}
