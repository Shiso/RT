/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 12:21:51 by tdeniset          #+#    #+#             */
/*   Updated: 2013/11/27 12:23:01 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (str && f)
	{
		i = 0;
		res = ft_strdup(str);
		while (res[i])
		{
			res[i] = (*f)(i, res[i]);
			i++;
		}
	}
	else
		res = "";
	return (res);
}
