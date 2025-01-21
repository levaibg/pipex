/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:44:07 by lloginov          #+#    #+#             */
/*   Updated: 2025/01/20 20:14:19 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
int parsing(int ac, char **av, t_pipex *p_pipex)
{
	(void)ac;
	p_pipex->infile = av[1];
	p_pipex->outfile = av[4];
	p_pipex->infile = av[1];
	p_pipex->cmd1 = av[2];
	p_pipex->cmd2 = av[3];
	p_pipex->outfile = av[4];
	innit_cmds(p_pipex);
	if(access(av[1], R_OK | W_OK) == -1)
	{
		printf("no permission for av 1\n");
		return(1);
	}
	if(access(av[4], R_OK | W_OK) == -1)
	{
		printf("no permission for av4\n");
		return(1);
	}
	return(0);
}

int	pipex(int ac, char **av, t_pipex *p_pipex, pid_t pid)
{
	parsing(ac,av, p_pipex);
	printf("pid : %d\n", pid);
	// char buffer[1024];
	(void)ac;
	int fd;
	int fd2[2];
	(void)pid;
	// int nb_read;

	fd = open("infile.txt", O_RDONLY | O_WRONLY | O_CREAT, 0644);
	printf("fd : %d\n", fd);
	if(fd == -1)
	{
		perror("caca");
		exit(1);
	}	
	if(access("infile.txt", R_OK) == -1)
	{
		printf("no permission\n");
		return(1);

	}
	// nb_read = read(fd,buffer, 9);
	// if(nb_read == -1)
	// 	return(1);
	if (pipe(fd2) == -1)
	{
		perror("pipe");
		exit(1);
	}
	(void)
	dup2(fd, STDOUT_FILENO);
	// read(fd2[0], buffer, 40);
	close(fd);	
	printf("le pid est %d \n", pid);
	// close(fd2[0]);
	return(0);
}

void	innit_cmds(t_pipex *p_pipex)
{
	char **res;

	res = ft_split(p_pipex->cmd1, ' ');
	int i = 0;

	while(res[i])
	{
		printf("first commad : %s\n", res[0]);
		i++;
	}
	i = 0;
	
	p_pipex->cmdfrist = res[0];
}