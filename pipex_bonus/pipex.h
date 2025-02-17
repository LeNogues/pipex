/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:28:48 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/02/17 15:55:41 by seb              ###   ########.fr       */
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
	char	*file;
	char	*full_path;
	char	**executable;
}				t_args;

//pipex.c
int		pipex(char **argv, char **envp);
//////////////////////////////////////////////////////// 

//executable.c
int		find_executable(char *command, char **full_path);
char	**create_executable1(char **argv);
char	**create_executable2(char **argv);
char	**create_executable_middle(char *str);
////////////////////////////////////////////////////////  

//mini_libft.c
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlcpy(char *dst, const char *src, int size);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
////////////////////////////////////////////////////////    

//parsing.c
char	*verif_arg1(char **argv, char **envp);
char	*verif_arg2(char **argv, char **envp);
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
char	**ft_split1(char const *s, char c);
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
void	execute_with_input(t_args *args, char **envp, int pipe_fd[2]);
////////////////////////////////////////////////////////

//handle_cmd.c
int		handle_first_cmd(char **argv, char **envp, int pipe_fd[2]);
int		handle_second_cmd(char **argv, char **envp, int pipe_fd[2]);
////////////////////////////////////////////////////////

//verif.c
int		verif_outfile(char *file);
int		verif_infile(char *file);
////////////////////////////////////////////////////////

//middle_cmd.c
void	loop_on_middle_cmd(char **argv, char **envp, int pipe_fd[2]);
////////////////////////////////////////////////////////

#endif