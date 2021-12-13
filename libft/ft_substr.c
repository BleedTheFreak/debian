/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaya <ytaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:52:32 by ytaya             #+#    #+#             */
/*   Updated: 2021/12/13 14:38:30 by ytaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substring;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	else if (len >= ft_strlen(s) - start)
		substring = (char *) malloc(sizeof(char) * ft_strlen(s) - start);
	else
		substring = (char *) malloc(sizeof(char) * len + 1);
	if (!substring)
		return (0);
	i = 0;
	while (s[i] && i < len && start < ft_strlen(s))
	{
		substring[i] = s[i + start];
		i++;
	}
	substring[i] = 0;
	return (substring);
}
