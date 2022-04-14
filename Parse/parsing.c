/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmeribaa <zmeribaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:42:01 by zmeribaa          #+#    #+#             */
/*   Updated: 2022/04/14 00:24:27 by zmeribaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void create_command(t_token **token)
{
	t_parse *command;
	int i;

	mini.command = init_commands();
	i = 0;
	command = mini.command;
	while (token[i])
	{
		factory(token, command, i);
		if (token[i]->type == T_RDRIN || token[i]->type == T_RDROUT 
			|| token[i]->type == T_APPEND || token[i]->type == T_HEREDOC)
			i++;
		if (token[i]->type == T_PIPE)
		{
			command->next = add_command();
			command = command->next;
		}
		i++;
	}
}

void parse(void)
{
	t_lexer *lexer;
	t_token **token;
	t_token *t;
	int i;
	
	lexer = init_lexer(mini.line);
	token = malloc(sizeof(struct s_token *) * 2);
	i = 0;
	token[0] = lexer_get_next_token(lexer);
	token[1] = NULL;
	while (token[i] != NULL)
	{
		i++;
		token = realloc_token(token, lexer_get_next_token(lexer));
	}
	create_command(token);
	free(lexer);
}