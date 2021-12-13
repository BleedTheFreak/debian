/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaya <ytaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:42:12 by ytaya             #+#    #+#             */
/*   Updated: 2021/12/13 14:38:34 by ytaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptrs1;
	unsigned char	*ptrs2;

	ptrs1 = (unsigned char *) s1;
	ptrs2 = (unsigned char *) s2;
	i = 0;
	while (ptrs1[i] && ptrs2[i] && i < n)
	{
		if (ptrs1[i] == ptrs2[i])
			i++;
		else
			break ;
	}
	if (i != n)
		return (ptrs1[i] - ptrs2[i]);
	return (0);
}
