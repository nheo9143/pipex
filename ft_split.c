/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heonamjun <nheo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:42:48 by heonamjun         #+#    #+#             */
/*   Updated: 2022/07/12 16:42:50 by heonamjun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	is_charset(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_count_strs(char const *s, char *charset)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s && !is_charset(charset, *s))
		{
			while (*s && !is_charset(charset, *s))
				s++;
			i++;
		}
		else
			s++;
	}
	return (i);
}

static size_t	ft_count_chars(char const *s, char *charset)
{
	size_t	i;

	i = 0;
	while (s[i] && !is_charset(charset, s[i]))
		i++;
	return (i);
}

static char const	*ft_next_strs(char const *s, char *charset, int i)
{
	if (i == 0)
		while (*s && is_charset(charset, *s))
			s++;
	else
		while (*s && !is_charset(charset, *s))
			s++;
	return (s);
}

char	**ft_split(char const *s, char *c)
{
	size_t	i;
	size_t	num_strs;
	char	**ptrs;

	i = 0;
	num_strs = ft_count_strs(s, c) + 1;
	ptrs = (char **)malloc(sizeof(char *) * num_strs);
	if (!ptrs)
		ft_error("malloc");
	while (i + 1 < num_strs)
	{
		s = ft_next_strs(s, c, 0);
		ptrs[i] = (char *)malloc(sizeof(char) * (ft_count_chars(s, c) + 1));
		if (!ptrs[i])
			ft_error("malloc");
		ft_strlcpy(ptrs[i++], s, ft_count_chars(s, c) + 1);
		s = ft_next_strs(s, c, 1);
	}
	return (ptrs);
}
