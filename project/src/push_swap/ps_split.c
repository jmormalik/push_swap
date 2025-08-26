/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:50:10 by jaemyu            #+#    #+#             */
/*   Updated: 2025/08/22 21:17:59 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_word_count(const char *s, char c, t_stack *stack)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != '-' && *s != '+' && (*s < '0' || *s > '9'))
			print_error(1, stack);
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*ft_word_dup(const char *start, size_t len)
{
	char	*word;
	size_t	i;

	i = 0;
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_free(char **arr, size_t i)
{
	while (i--)
		free(arr[i]);
	free(arr);
	return (NULL);
}

static char	**ft_split_word(char **arr, char const *s, char c)
{
	const char	*start;
	size_t		len;
	size_t		i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			start = s;
			while (*s && *s != c)
				s++;
			len = s - start;
			arr[i] = ft_word_dup(start, len);
			if (!arr[i++])
			{
				ft_free(arr, i);
				return (NULL);
			}
		}
	}
	arr[i] = NULL;
	return (arr);
}

char	**ps_split(char const *s, char c, t_stack *stack)
{
	char		**arr;
	size_t		count;

	if (!s)
		return (NULL);
	count = ft_word_count(s, c, stack);
	if (! count)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	return (ft_split_word(arr, s, c));
}
