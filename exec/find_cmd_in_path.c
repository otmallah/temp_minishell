/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_in_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:43:43 by otmallah          #+#    #+#             */
/*   Updated: 2022/04/06 17:44:04 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *ft_getenv(char *str, t_mini *index)
{
	int i;
	char *temp;

	i = 0;
	while (index->string[i])
	{
		temp = ft_substr(index->string[i], 0, find_len3(index->string[i]));
		if (ft_strcmp(temp, str) == 0)
			return (ft_strchr(index->string[i], '/'));
		i++;
	}
	return NULL;
}
