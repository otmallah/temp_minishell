/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziyad <ziyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:01:25 by zmeribaa          #+#    #+#             */
/*   Updated: 2022/04/06 20:34:58 by zmeribaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

typedef struct s_lexer 
{
	char c;
	unsigned int i;
	char *contents;
}	t_lexer;

typedef enum e_type
{
		T_WORD,
		T_RDRIN,
		T_RDROUT,
		T_HEREDOC,
		T_APPEND,
		T_PIPE,
}	t_type;

typedef struct s_token
{
	int type;
	char *value;
}		t_token;

typedef struct s_redirection
{
	int						type;
	char					*file;
	int						fd;
	struct s_redirection	*next;
}							t_redirection;
 
typedef struct s_parse
{
	char			*cmd;
	char			**args;
	int				argsc;
	t_redirection	*redirection;
	struct s_parse	*next;
}				t_parse;

t_parse			par;

t_token	*init_token(int token, char *value);

t_lexer	*init_lexer(char *contents);

void lexer_advance(t_lexer *lexer);

void lexer_skip_whitespace(t_lexer *lexer);

t_token *lexer_get_next_token(t_lexer *lexer);

t_token *lexer_collect_string(t_lexer *lexer, char c);

char *lexer_get_current_char_as_string(t_lexer *lexer);

t_token	*lexer_advance_with_token(t_lexer *lexer, t_token *token);


t_token	*lexer_collect_word(t_lexer *lexer);


char *join_string(t_lexer *lexer, char c);
char	*join_word(t_lexer *lexer);
char	*after_quotes(t_lexer *lexer, char *val);

char *expandInWord(t_lexer *lexer);
char *expandInQuotes(t_lexer *lexer);

void lexer_retreat(t_lexer *lexer);

char *my_getenv(char *env);

char	*expandCheck(t_lexer *lexer, char *s);


void	add_redirecion(t_redirection *head, char *val, t_type type);

t_redirection *init_redirection(char *val, t_type type);

t_parse	*init_commands(void);
t_parse *add_command(void);
void factory(t_token **token, t_parse *command, int i);
void create_command(t_token **token);
t_token **realloc_token(t_token **curr, t_token *token);
void parse(void);
#endif

