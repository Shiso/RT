/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 11:54:44 by tdeniset          #+#    #+#             */
/*   Updated: 2013/11/27 12:18:32 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *str, char (*f)(char c))
{
	char			*res;
	unsigned int	i;

	if (str && f)
	{
		i = 0;
		res = ft_strdup(str);
		while (res[i])
		{
			res[i] = (*f)(res[i]);
			i++;
		}
	}
	else
		res = "";
	return (res);
}
