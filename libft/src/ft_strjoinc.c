/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 16:36:01 by tdeniset          #+#    #+#             */
/*   Updated: 2014/01/06 16:36:51 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinc(const char *s1, const char *s2, char c)
{
	char	*res;

	if (s1 && s2)
	{
		if (ft_strlen(s1) != 0)
			res = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 2);
		else
			res = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		ft_strcat(res, s1);
		if (ft_strlen(s1) != 0)
			ft_strcat(res, &c);
		ft_strcat(res, s2);
	}
	else
		res = "";
	return (res);
}
