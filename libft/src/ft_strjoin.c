/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 14:09:30 by tdeniset          #+#    #+#             */
/*   Updated: 2013/11/27 14:22:15 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;

	if (s1 && s2)
	{
		res = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		ft_strcat(res, s1);
		ft_strcat(res, s2);
	}
	else
		res = "";
	return (res);
}
