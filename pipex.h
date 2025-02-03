/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:28:48 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/02/03 15:32:26 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>

//executable.c
int		find_executable(char *command, char **full_path);
char	**create_executable(int argc, char **argv);
////////////////////////////////////////////////////////  

//mini_libft.c
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlcpy(char *dst, const char *src, int size);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
////////////////////////////////////////////////////////    

//parsing.c
char	*verif_arg(int argc, char **argv, char *full_path, char **envp);
////////////////////////////////////////////////////////

//path.c
char	*get_path(char **envp);
char	*ft_write_mini_path(char *mini_path, char *dir, char *command);
////////////////////////////////////////////////////////

//strtok.c
char	*ft_strtok(char *str, const char delim);
////////////////////////////////////////////////////////
#endif