/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaya <ytaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:24:28 by ytaya             #+#    #+#             */
/*   Updated: 2021/12/13 14:38:57 by ytaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_r(char **s)
{
	unsigned int	k;

	k = 0;
	while (s[k])
	{
		free(s[k]);
		k++;
	}
	free(s);
	return (NULL);
}

static unsigned int	ft_getnwords(const char *s, char c)
{
	unsigned int	i;
	unsigned int	n;

	n = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			n++;
			while (s[i + 1] && s[i + 1] != c)
				i++;
		}
		i++;
	}
	return (n);
}

static unsigned int	ft_getwordsize(const char *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_strucpy(const char *s, unsigned int n)
{
	char			*d;
	unsigned int	i;

	i = 0;
	d = (char *)malloc(sizeof(char) * (n + 1));
	if (!(d))
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	n;
	char			**table;
	unsigned int	i;

	if (!(s))
		return (NULL);
	n = ft_getnwords(s, c);
	table = (char **)malloc(sizeof(char *) * + (n + 1));
	i = 0;
	if (!(table))
		return (NULL);
	while (i < n)
	{
		while (*s && (char)*s == c)
			s++;
		table[i] = ft_strucpy(s, ft_getwordsize(s, c));
		if (!(table[i]))
			return (free_r(table));
		s += ft_getwordsize(s, c);
		i++;
	}
	table[i] = 0;
	return (table);
}
