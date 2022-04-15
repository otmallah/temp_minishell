#include "../Parse/minishell_exec.h"

int	find_space2(char *tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if(tab[i] == ' ')
			return 1;
		i++;
	}
	return 0;
}

void	find_path(t_parse *iterator, t_pipe *index, t_mini *idx)
{
	int i;
	int a;
	char *temp;
	char **tep;

	i = 0;
	ft_check_cmd(iterator, idx);
	temp = getenv("PATH");
	index->tab = ft_split(temp, ':');
	while (index->tab[i])
	{
		//printf("%s \n", iterator->cmd);
		a = ft_strlen(index->tab[i]);
		index->tab[i][a] = '/'; // bach tkoun lpath kamla n '/'
		index->tab[i][a + 1] = '\0'; // bach nsali string
		index->str = ft_strjoin(index->tab[i], iterator->cmd);
		if (access(index->str, F_OK) == 0)
		{
			execve(index->str, &iterator->args[0], index->string);
		}
		i++;
	}
	write (2, "command not found:", 18);
	write (2, iterator->cmd, ft_strlen(iterator->cmd));
	write(2, "\n", 1);
	exit(0);
}

void	find_heredoc2(t_pipe *pipx, t_mini *index, t_idx *id, t_parse *iterator)
{
	t_parse *temp;

	temp = iterator;
	while (iterator)
	{
		if (iterator->redirection)
		{
			while(iterator->redirection)
			{
				//printf("cmd = [%s]\n", iterator->cmd);
				if (iterator->redirection->type == T_HEREDOC)
				{
					ft_heredoce(index, id, pipx, iterator);	
				}
				//printf("file [%s] \n", iterator->redirection->file);
				iterator->redirection = iterator->redirection->next;
			}
			//ft_heredoce(index, id, pipx, iterator);
		}
		iterator = iterator->next;
	}
}

void	find_redirection(t_mini *index, t_idx *id, t_pipe *pipx, t_parse *iteratore)
{
	iteratore = mini.command;
	while (iteratore)
	{
		if (iteratore->redirection)
		{
			while(iteratore->redirection)
			{
				if (iteratore->redirection->type == T_RDROUT)
					ft_redirections(index, id, pipx, iteratore);
				if (iteratore->redirection->type == T_RDRIN)
					ft_redirections(index, id, pipx, iteratore);
				if (iteratore->redirection->type == T_APPEND)
					ft_redirections(index, id, pipx, iteratore);
				iteratore->redirection = iteratore->redirection->next;
			}
		}
		iteratore = iteratore->next;
	}
}

int 	nbr_of_cmds2(t_parse *head)
{
	int i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

int ft_pipe(t_mini *index, t_pipe *pipx, t_idx *idx, t_parse *iterator)
{
	int fd[2];
	char *str;
	t_parse *temp;
	int a;
	int i;
	int sp;
	int id;
	int pid[100];

	find_heredoc2(pipx, index, idx, iterator);
	find_redirection(index, idx, pipx, iterator);
	a = nbr_of_cmds2(mini.command);
	//iterator = mini.command;
	i = 0;
	int ff = 0;
	while (i < a)
	{
		//puts("*-*-**********************************************");
		if (iterator->redirection)
		{
			while (iterator->redirection)
			{
				if(iterator->redirection->type == T_RDROUT)
					iterator = iterator->next;
				else
					break ;
				iterator->redirection = iterator->redirection->next;
			}
		}
		if (pipe(fd) == -1)
			return 1;
		id = fork();
		if (id == 0)
		{
			if (i == 0)
			{
				close(fd[0]);
				dup2(0, 0);
				dup2(fd[1], STDOUT_FILENO);
				find_path(iterator, pipx ,	index);
			}
			else if (i == (a - 1))
			{
				close(fd[0]);
				close(fd[1]);
				dup2(ff, STDIN_FILENO);
				dup2(1, 1);
				find_path(iterator, pipx , index);
			}
			else
			{
				close(fd[0]);
				dup2(ff, STDIN_FILENO);
				dup2(fd[1], STDOUT_FILENO);
				find_path(iterator, pipx , index);
			}
		}
		pid[i] = id;
		ff = dup(fd[0]);
		close(fd[0]);
		close(fd[1]);
		iterator = iterator->next;
		i++;
	}
	while (--i >= 0)
		waitpid(pid[i], 0, 0);
	return 0;
}

// int		find_pipe(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '|')
// 			return 1;
// 		i++;
// 	}
// 	return 0;
// }

// void	check_pipe(t_pipe *pipe, t_mini *index, t_idx *id, char *str)
// {
// 	int a;

// 	a = find_pipe(str);
// 	if (a == 1)
// 	{
// 		pipe->tab = ft_split(str, '|');
// 		ft_pipe(index, pipe, id);
// 	}
// }


// int main(int ac, char **av, char **env)
// {
// 	t_mini index;
// 	t_idx id;
// 	t_pipe pipx;

// 	index.count2 = 0;
// 	index.finde = NULL;
// 	index.tab_exp = env;
// 	index.string = env;
// 	index.tab_unset = env;
// 	id.c = 0;
// 	id.cnt = 0;
// 	id.a = 0;
// 	id.b = 0;
// 	id.d = 0;
// 	id.poor = 1;
// 	id.cot = 0;
// 	check_pipe(&pipx, &index, &id, av[1]);
// }