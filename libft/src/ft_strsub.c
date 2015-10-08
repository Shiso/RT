/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 12:47:31 by tdeniset          #+#    #+#             */
/*   Updated: 2014/01/12 22:46:40 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t n)
{
	char			*res;
	unsigned int	i;

	if (s && n && start < ft_strlen(s))
	{
		res = malloc(n + 1);
		i = 0;
		while (i < n)
		{
			res[i] = s[start + i];
			i++;
		}
		res[i] = '\0';
	}
	else
		res = "";
	return (res);
}
