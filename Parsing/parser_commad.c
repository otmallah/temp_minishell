/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_commad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 02:03:13 by zmeribaa          #+#    #+#             */
/*   Updated: 2022/04/12 16:31:30 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	array_len(char **array)
{
	int i;

	i = 0;
	if(array)
	{
		while (array[i])
			i++;
	}
	return (i);
} 

char **realloc_args_array(char **curr, char *arg)
{
	char **new_args;
	int i;
	int l;

	if (arg[0] == ' ' && arg[1] == '\0')
		return (curr);
	l = array_len(curr);
	i = 0;
	new_args = (char **)malloc(sizeof(char *) * (l + 2));
	while (i < l)
	{
		new_args[i] = (curr[i]);
		i++;
	}
	free(curr);
	new_args[i++] = ft_strdup(arg);
	new_args[i] = NULL;
	return (new_args);
}

t_parse	*init_commands(void)
{
	t_parse *cmd;
	
	cmd = (t_parse *)malloc(sizeof(t_parse));
	cmd->cmd = NULL;
	cmd->args = NULL;
	cmd->argsc = 0;
	cmd->next = NULL;

	return (cmd);
}

t_parse *add_command(void)
{
	t_parse *new;
	
	new = (t_parse *)malloc(sizeof(t_parse));
	new->cmd = NULL;
	new->args = NULL;
	new->argsc = 0;
	new->redirection = NULL;
	new->next = NULL;
	return (new);
}


void factory(t_token **token, t_parse *command, int i)
{
	if (token[i]->type == T_WORD)
	{
		if (command->args == NULL)
			command->cmd = ft_strdup(token[i]->value);
		command->args = realloc_args_array(command->args, token[i]->value);
	}
	else if (token[i]->type == T_RDRIN || token[i]->type == T_RDROUT 
			|| token[i]->type == T_APPEND || token[i]->type == T_HEREDOC)
	{
		if (command->redirection == NULL)
			command->redirection = init_redirection(token[i + 1]->value, token[i]->type);
		else
			add_redirecion(command->redirection, token[i + 1]->value, token[i]->type);
	}
}
