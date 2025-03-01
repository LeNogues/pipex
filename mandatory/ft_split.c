/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:11:31 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/03/01 12:35:52 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	detect;

	if (!str)
		return (0);
	i = 0;
	detect = 0;
	while (*str)
	{
		if (*str != c && detect == 0)
		{
			detect = 1;
			i++;
		}
		else if (*str == c)
			detect = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	free_tab(char **tab, int j)
{
	int	i;

	i = 0;
	while (i < j)
		free(tab[i++]);
	free(tab);
}

static int	split_string(const char *s, char c, char **tab)
{
	int	i;
	int	j;
	int	start;
	int	len;

	i = 0;
	j = 0;
	start = -1;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == len) && start >= 0)
		{
			tab[j] = word_dup(s, start, i);
			if (!tab[j])
				return (free_tab(tab, j),0);
			j++;
			start = -1;
		}
		i++;
	}
	tab[j] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s || !c)
		return (NULL);
	if (s[0] == 32 && s[1] == 0)
	{
		tab = malloc(sizeof(char *) * 1);
		if (!tab)
			return (NULL);
		tab[0] = NULL;
		return (tab);
	}
	tab = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		exit(EXIT_FAILURE);
	if (!split_string(s, c, tab))
		return (NULL);
	return (tab);
}
