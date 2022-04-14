/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmeribaa <zmeribaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:16:30 by zmeribaa          #+#    #+#             */
/*   Updated: 2022/04/11 22:42:58 by zmeribaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token *init_token(int type, char *value)
{
	t_token *token;

	token = calloc(1, sizeof(struct s_token));
	token->type = type;
	token->value = value;

	return (token);
}

int	token_array_l(t_token **token)
{
	int	i;

	i = 0;
	if (token)
	{
		while (token[i] != NULL)
			i++;
	}
	return (i);
}

t_token **realloc_token(t_token **curr, t_token *token)
{
	t_token **new_token;
	int i;
	int l;

	l = token_array_l(curr);
	i = 0;
	new_token = (t_token **)malloc(sizeof(t_token *) * (l + 2));
	while (i < l)
	{
		new_token[i] = (curr[i]);
		i++;
	}
	free(curr);
	new_token[i++] = token;
	new_token[i] = NULL;
	return (new_token);
}