/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 14:54:39 by tdeniset          #+#    #+#             */
/*   Updated: 2014/01/12 22:47:44 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_ilen(int i);

char			*ft_itoa(int i)
{
	char			*res;
	unsigned int	len;

	len = ft_ilen(i);
	res = ft_strnew(len);
	if (i < 0)
	{
		res[0] = '-';
	}
	if (i == 0)
	{
		res[0] = '0';
	}
	while (i != 0)
	{
		if (i > 0)
			res[--len] = (i % 10) + '0';
		else
			res[--len] = -(i % 10) + '0';
		i /= 10;
	}
	return (res);
}

static size_t	ft_ilen(int i)
{
	size_t	len;

	len = 0;
	if (i <= 0)
	{
		len++;
		i = -i;
	}
	while (i != 0)
	{
		i /= 10;
		len++;
	}
	return (len);
}
