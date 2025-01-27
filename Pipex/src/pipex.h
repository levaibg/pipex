/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:04:09 by lloginov          #+#    #+#             */
/*   Updated: 2025/01/23 16:09:08 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h> 
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stddef.h>
# define NC "\e[0m"		  // reset color
# define YELLOW "\e[1;33m" // yellow
# define BLUE "\e[1;34m"	  // bleu
# define GREEN "\e[1;32m"  // green
# define RED "\e[1;31m"	  // red
# define PURPLE "\033[0;35m" // violette


typedef struct t_pipex
{
	int n_read;
	char *infile;
	char *outfile;
	char *buffer;
	char *env_siz;
	char *env_dup;
	char **cmd1;
	char **cmd2;
	char *cmdfrist;
	

}	t_pipex;

//int main
int main(int ac, char **av, char **env);
//pipex
int	pipex(int ac, char **av, t_pipex *p_pipex, pid_t pid);
int parsing(int ac, char **av, t_pipex *p_pipex);
//utils#include <stdlib.h>

void	ft_innit_pip(t_pipex *p_pipex);
void	ft_putstr(char *str);
char  *find_env(char **env, t_pipex *p_pipex, char *cmd);
// char *strcmp(char *s1, char *s2);

//split
char	**ft_split(const char *s, char c);
void	innit_cmds(char **av, t_pipex *p_pipex);
int	ft_strlen(const char *str);
char	*ft_strjoin( char *s1,  char *s2);
char	*ft_strdup(const char *src);
void	exec_pere(char **av, t_pipex *p_pipex, char **env);
void	exec_fils(char **av, t_pipex *p_pipex, char **env);


# endif