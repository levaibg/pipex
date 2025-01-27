/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:44:07 by lloginov          #+#    #+#             */
/*   Updated: 2025/01/23 17:02:43 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
int parsing(int ac, char **av, t_pipex *p_pipex)
{
	(void)ac;
	p_pipex->outfile = av[4];
	p_pipex->infile = av[1];
	p_pipex->outfile = av[4];
	innit_cmds(av, p_pipex);
	if(access(av[1], R_OK) == -1)
	{
		printf("no permission for av 1\n");
		exit(1);
	}
	if(access(av[4], W_OK) == -1)
	{
		printf("no permission for av4\n");
		exit(1);
	}
	return(0);
}

void	exec_fils(char **av, t_pipex *p_pipex, char **env, int *fd)
{
	int fdin;
	char *path;
	
	fdin = open(av[1],O_RDONLY);

	if(fdin == -1)
	{
		printf("error\n");
		exit(1);
	}
	dup2(fd[1], STDOUT_FILENO);
	dup2(fdin,STDIN_FILENO);
	close(fd[0]);
	path = find_env(env, p_pipex, p_pipex->cmd1[0]);
	if(path == NULL)
		printf("cant find commande\n");
	else
	{
		fprintf(stderr, "path : %s\n", path);
		fprintf(stderr, "cmd2: %s\n", p_pipex->cmd2[0]);
		fprintf(stderr, "cmd2: %s\n", p_pipex->cmd2[1]);
		if (execve(path, p_pipex->cmd2, env) == -1)
		{
			    perror("execve failed");
				exit(1);
		}
	}
}

void	exec_pere(char **av, t_pipex *p_pipex, char **env, int *fd)
{
	char *path;
	int fdout;

	fdout =  open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if(fdout == -1)
	{
		printf("error\n");
		exit(1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
	close(fd[1]);
	path = find_env(env, p_pipex, p_pipex->cmd2[0]);
	if(path == NULL)
		printf("cant find commande\n");
	else
	{
		if(execve(path, p_pipex->cmd2, env) == -1)
		{
			    perror("execve failed");
				exit(1);
		}
	}
}


void	innit_cmds(char **av, t_pipex *p_pipex)
{
	char **res;
	char **res2;

	res = ft_split(av[2], ' ');
	p_pipex->cmd1 = res;
	res2 = ft_split(av[3], ' ');
	p_pipex->cmd2 = res2;
}