/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:12:13 by lloginov          #+#    #+#             */
/*   Updated: 2025/01/20 20:21:22 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int ft_strcmp2(char *s1, char *s2, t_pipex *p_pipex)
{
	int i;

	i = 0;
	
	while(s2[i])
	{
		if(s1[i] == s2[i])
			i++;
		else
			return(1);
	}
	i = 0;

	while(s1[i])
		i++;
	p_pipex->env_siz = malloc(sizeof(char *) * i + 1);
	if(!p_pipex->env_siz)
	{
		printf("malloc erroe\n");
		exit(1);
	}
	return(0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}


void	ft_putstr(char *str)
{
	int i;

	i = 0;

	while(str[i])
	{
		write(1,&str[i],1);
		i++;
	}
}


void	ft_innit_pip(t_pipex *p_pipex)
{

	p_pipex->n_read = 0;
	p_pipex->infile = NULL;
	p_pipex->outfile = NULL;
	p_pipex->buffer = NULL;
	p_pipex->env_siz = NULL;
	p_pipex->env_dup = NULL;
	p_pipex->cmd1 = NULL;
	p_pipex->cmd2 = NULL;
	p_pipex->cmdfrist =NULL;
}


void find_env(char **env, t_pipex *p_pipex)
{
	// int i;
	// int j;

	// // int i;
	int j;

	// // i = 0;
	j = 0;

	while(env[j])
	{
		if(ft_strcmp2(env[j], "PATH=", p_pipex) == 0)
		{
			p_pipex->env_siz = env[j] + 5;
			printf("voici ppex %s\n", p_pipex->env_siz);
		}
		j++;
	}
	char **res;
	res = ft_split(p_pipex->env_siz, ':');
	// ft_strjoin(res, p_pipex->cmdfrist);
	int k = 0;
	while(1)
	{
		if(access(res[k],R_OK) != -1)
		{
			printf("cbon\n");
			return;
		}
		else
			res[k] = ft_strjoin(res[k], res[k + 1]);
		if(ft_strcmp(res[k], p_pipex->env_siz) == 0)
		{
			printf("Erorr : m=path ma bite\n");
			return;
		}
		while(res[k])
		{
			printf("voici res : %s\n", res[k]);
			k++;
		}
	}










	// while(k != 12)
	// {
	// 	printf("cmdfir : %s\n", p_pipex->cmdfrist);
	// 	if(access(res,R_OK) != -1)
	// 	{
	// 		printf("cbon\n");
	// 		return;
	// 	}
	// 	else
	// 		res = ft_strjoin(res, ':');
	// 	if(ft_strcmp(res, p_pipex->env_siz) == 0)
	// 	{
	// 		printf("Erorr : m=path ma bite\n");
	// 		return;
	// 	}
	// 	// printf("\n ENV %d = %s\n P_PIPEX = %s\n", k, res, p_pipex->env_siz);
	// 	k++;
	// 	printf("\n ENV %d = %s\n", k, res);
	// }

}

