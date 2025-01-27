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
	p_pipex->infile = av[1];
	p_pipex->outfile = av[4];
	p_pipex->infile = av[1];
	p_pipex->outfile = av[4];
	innit_cmds(av, p_pipex);
	if(access(av[1], R_OK | W_OK) == -1)
	{
		printf("no permission for av 1\n");
		exit(1);
	}
	if(access(av[4], R_OK | W_OK) == -1)
	{
		printf("no permission for av4\n");
		exit(1);
	}
	return(0);
}

void	exec_pere(char **av, t_pipex *p_pipex, char **env)
{
	int i;
	char *path;
	i = 0;
	(void)i;
	(void)av;
	path = find_env(env, p_pipex, p_pipex->cmd2[0]);
	if(path == NULL)
		printf("cant find commande\n");
	else
	{
		if(execve(path, p_pipex->cmd2, NULL) == -1)
		{
			printf("error\n");
		}
	}

		
}

void	exec_fils(char **av, t_pipex *p_pipex, char **env)
{
	(void)av;
	if(find_env(env, p_pipex, p_pipex->cmd1[0]) == NULL)
		printf("cant find commande\n");
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