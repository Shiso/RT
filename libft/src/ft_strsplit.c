/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 13:49:14 by tdeniset          #+#    #+#             */
/*   Updated: 2014/01/12 22:47:15 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getlen(const char *s, char c);
static size_t	ft_strlchr(const char *s, char c);

char			**ft_strsplit(const char *s, char c)
{
	char			**av;
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;
	unsigned int	temp;

	len = ft_getlen(s, c);
	av = malloc(sizeof (char *) * (len + 1));
	i = 0;
	j = 0;
	while (s[i])
	{
		temp = ft_strlchr(s + i, c);
		if (temp)
		{
			av[j] = ft_strsub(s, i, temp);
			j++;
			i+= temp;
		}
		else
			i++;
	}
	av[j] = '\0';
	return (av);
}

static size_t	ft_getlen(const char *s, char c)
{
	unsigned int	i;
	unsigned int	temp;
	size_t			len;

	i = 0;
	len = 0;
	while (s[i])
	{
		temp = ft_strlchr(s + i, c);
		if (temp)
		{
			len += 1;
			i += temp;
		}
		else
			i++;
	}
	return (len);
}

static size_t	ft_strlchr(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}
