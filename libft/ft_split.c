/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paroonag <paroonag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 10:54:26 by paroonag          #+#    #+#             */
/*   Updated: 2021/06/22 19:44:28 by paroonag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_clear(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free (s[i]);
		i++;
	}
	free (s);
	return (0);
}

static unsigned int	count_w(char *s, char c)
{
	unsigned int	co;

	co = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (!*s)
			break ;
		while (*s && *s != c)
			++s;
		++co;
	}
	return (co);
}

static char	*split_w(char *start, int n)
{
	char	*p;
	int		i;

	p = (char *)malloc(sizeof(char) * (n + 1));
	if (!p)
		return (0);
	i = 0;
	while (i < n)
	{
		p[i] = start[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char			**str;
	char			*start;
	unsigned int	size_word;
	unsigned int	i;

	size_word = count_w((char *)s, c);
	str = (char **)malloc(sizeof(char *) * (size_word + 1));
	if (!s || !str)
		return (0);
	i = 0;
	while (i < size_word)
	{
		while (*s == c)
			++s;
		start = (char *)s;
		while (*s != c && *s)
			++s;
		str[i] = split_w(start, s - start);
		if (!str[i])
			return (ft_clear(str));
		++i;
	}
	str[i] = 0;
	return (str);
}
