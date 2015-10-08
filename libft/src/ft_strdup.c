/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:47:52 by tdeniset          #+#    #+#             */
/*   Updated: 2013/11/27 12:19:57 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlen(const char *);
char	*ft_strcpy(char *, const char *);

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = malloc(sizeof (*s1) * ft_strlen(s1));
	ft_strcpy(str, s1);
	return (str);
}
