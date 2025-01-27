/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:03:53 by lloginov          #+#    #+#             */
/*   Updated: 2025/01/23 16:09:08 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **env)
{
	t_pipex p_pipex;
	pid_t pid;
	int fdp[2];
	if(ac != 5)
	{
		perror("Error : args\n");
		return(1);
	}
	else
	{
		ft_innit_pip(&p_pipex);
	}
	parsing(ac,av,&p_pipex);
	pipe(fdp);
	pid = fork();
	if(pid == -1)
	{
		printf("errore pid -1\n");
		return(1);
	}
	if(pid == 0)
	{
		// printf("je suis fils\n");
		exec_fils(av, &p_pipex, env, fdp);	
	}
	else
	{	
		// printf("prend exemple fils mon pid est %d\n", getpid());
		exec_pere(av, &p_pipex, env, fdp);
	}
	
	return(0);	
}