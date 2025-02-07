/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:28:48 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/02/07 15:25:47 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_args
{
	char	*outfile;
	char	*full_path;
	char	**executable;
}				t_args;

//pipex.c
int		pipex(int argc, char **argv, char **envp);
//////////////////////////////////////////////////////// 

//executable.c
int		find_executable(char *command, char **full_path);
char	**create_executable1(int argc, char **argv);
char	**create_executable2(int argc, char **argv);
////////////////////////////////////////////////////////  

//mini_libft.c
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlcpy(char *dst, const char *src, int size);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
////////////////////////////////////////////////////////    

//parsing.c
char	*verif_arg(char **argv, char **envp);
////////////////////////////////////////////////////////

//path.c
char	*get_path(char **envp);
char	*ft_write_mini_path(char *mini_path, char *dir, char *command);
////////////////////////////////////////////////////////

//strtok.c
char	*ft_strtok(char *str, const char delim);
////////////////////////////////////////////////////////

//ft_split.c
char	**ft_split(char const *s, char c);
////////////////////////////////////////////////////////

//clean.c
void	free_path_exec(char *full_path, char **executable);
void	free_executable(char **executable);
////////////////////////////////////////////////////////

//error.c
void	error_message(int error_code);
////////////////////////////////////////////////////////

//exec.c
void	exec1(char *full_path, char **executable, char **envp, int pipe_fd[2]);
void	exec2(char *full_path, char **executable, char **envp, int pipe_fd[2]);
void	execute_with_output(t_args *args, char **envp, int pipe_fd[2]);
////////////////////////////////////////////////////////

//handle_cmd.c
int		handle_first_cmd(int argc, char **argv, char **envp, int pipe_fd[2]);
int		handle_second_cmd(int argc, char **argv, char **envp, int pipe_fd[2]);
////////////////////////////////////////////////////////
#endif