/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 15:00:56 by tdeniset          #+#    #+#             */
/*   Updated: 2014/01/12 22:45:59 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	unsigned int	x;
	unsigned int	l;
	char			*res;

	if (s)
	{
		while (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		l = ft_strlen(s);
		if (l)
			while (s[l - 1] == ' ' || s[l - 1] == '\n' || s[l - 1] == '\t')
				l--;
		res = ft_strnew(l);
		x = 0;
		while (x < l)
		{
			res[x] = s[x];
			x++;
		}
	}
	else
		res = "";
	return (res);
}
