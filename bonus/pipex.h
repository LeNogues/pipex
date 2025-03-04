/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:28:48 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/03/01 12:22:01 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_args
{
	char	*file;
	char	*full_path;
	char	**executable;
}			t_args;

typedef struct s_here_doc
{
	char	**cmd1;
	char	**cmd2;
	char	*limiter;
	char	*file;
	int		state;
}			t_here_doc;

typedef struct s_pipe
{
	int		old[2];
	int		new[2];
}			t_pipe;

// pipex.c
int			pipex(int argc, char **argv, char **envp);
////////////////////////////////////////////////////////

// executable.c
int			find_executable(char *command, char **full_path);
char		**create_executable1(char **argv);
char		**create_executable2(int argc, char **argv);
char		**create_executable_middle(char *str);
////////////////////////////////////////////////////////

// mini_libft.c
int			ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strlcpy(char *dst, const char *src, int size);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
////////////////////////////////////////////////////////

// parsing.c
char		*verif_arg(char **argv, char **envp);
////////////////////////////////////////////////////////

// path.c
char		*get_path(char **envp);
char		*ft_write_mini_path(char *mini_path, char *dir, char *command);
////////////////////////////////////////////////////////

// strtok.c
char		*ft_strtok(char *str, const char delim);
////////////////////////////////////////////////////////

// ft_split.c
char		**ft_split(char const *s, char c);
char		**ft_split1(char const *s, char c);
////////////////////////////////////////////////////////

// clean.c
void		free_path_exec(char *full_path, char **executable);
void		free_executable(char **executable);
////////////////////////////////////////////////////////

// error.c
void		error_message(int error_code);
////////////////////////////////////////////////////////

// exec.c
void		exec1(char *full_path, char **executable, char **envp,
				t_pipe pipe_fd);
void		exec2(char *full_path, char **executable, char **envp,
				t_pipe pipe_fd);
void		execute_with_output(t_args *args, char **envp, t_pipe pipe_fd);
void		execute_with_input(t_args *args, char **envp, t_pipe pipe_fd);
void		execute_middle(t_args *args, char **envp, t_pipe pipe_fd);
////////////////////////////////////////////////////////

// handle_cmd.c
int			handle_first_cmd(char **argv, char **envp, t_pipe *pipe_fd);
int			handle_last_cmd(int argc, char **argv, char **envp, t_pipe pipe_fd);
////////////////////////////////////////////////////////

// verif.c
int			verif_outfile(char *file);
int			verif_infile(char *file);
////////////////////////////////////////////////////////

// middle_cmd.c
int			loop_on_middle_cmd(int argc, char **argv, char **envp,
				t_pipe *pipe_fd);
void		pipecpy(int new_fd[2], int old_fd[2]);
////////////////////////////////////////////////////////

//here_doc.c
int here_doc(char **argv, t_here_doc hd, char **envp);
////////////////////////////////////////////////////////

//get_next_line
char	*get_lines(char *buffer, char *init_line);
void	next_line(char *buffer);
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_bzero(void *s, size_t n);
////////////////////////////////////////////////////////


#endif