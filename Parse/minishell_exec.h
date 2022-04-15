#ifndef MINISHELL_EXEC_H
# define MINISHELL_EXEC_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "parser.h"
#include <readline/readline.h>
#include <readline/history.h>

int FD_TE;

typedef struct s_minishell
{
	int		cnt;
	t_parse *command;
	char 	*line;
	char 	*str;
	char 	**env_tab;
	char 	*finde;
	char 	**string;
	char 	**tab;
	char 	**tab_exp;
	char 	**tab_e;
	char 	*check;
	char	**tab_unset;
	char	*append_str;
	int 	count2;
}	t_mini;

t_mini mini;

typedef struct s_pipe
{
	char **tab;
	char *str;
	char **string;
}	t_pipe;

typedef struct s_idx
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	cnt;
	int	cot;
	int	poor;
}	t_idx;

typedef struct s_list {
	void			*content;
	struct s_list	*next;
}		t_list;

int	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char l);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	ft_pwd(t_parse *iterator);
void    ft_cd(char *path);
char	*ft_strchr(const char *str, int c);
void    ft_exit(t_mini *index);
void    ft_env(t_mini *index, t_idx *id);
void	ft_echo(t_parse *iteratore);
void	ft_export(t_mini *index, t_idx *id, char *str);
void	ft_print_export(t_mini *index, t_idx *id, char *str);
void	ft_unset(t_mini *index, t_idx *id, char *str);

// utils

int		ft_strcmp(char *s1, char *s2);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
char	*ft_strrchr(const char *str, int c);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
char	*get_next_line(int fd);

//utils export

int		find_dup(t_mini *index, t_idx *id, char *find);
int		find_len4(char *str);
void	add_to_temp(t_mini *index, t_idx *id);
int		find_duplicate(t_mini *index, char *str,t_idx *id);
void	add_to_temp2(t_mini *index, t_idx *id);
int		find_value(char *str);
int		find_len(char *str);
int    find_space(char *str);

//utils unset

void    add_to_temp_env(t_mini *index, t_idx *id, char *str);
void    add_to_temp_expo(t_mini *index, t_idx *id, char *str);

//pipe

int ft_pipe(t_mini *index, t_pipe *pipx, t_idx *idx, t_parse *iterator);
void	func_all(t_mini *index, t_parse *iterator);
char	*ft_getenv(char *str, t_mini *index);

//redirections

void	ft_redirections(t_mini *index, t_idx *id, t_pipe *pipx, t_parse *iterator);
int	find_path_red(t_pipe *index, t_parse *iterator);
void    ft_heredoce(t_mini *index, t_idx *id, t_pipe *pipx, t_parse *iterator);
int		find_pipe(char *str);

//signals

void    sigint_handler(int signum);

#endif