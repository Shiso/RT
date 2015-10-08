/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 12:23:15 by smakroum          #+#    #+#             */
/*   Updated: 2014/02/23 23:34:08 by mgarcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isline(char **buff)
{
	char	*ptr_n;

	ptr_n = ft_strchr(*buff, '\n');
	if (!ptr_n)
		return (-1);
	return (ptr_n - *buff);
}

int		ft_stock(char **line, char **buff, int pos)
{
	char	*tmp;

	*line = ft_strnjoin(*line, *buff, pos);
	tmp = ft_strsub(*buff, pos + 1, ft_strlen(*buff) - pos - 1);
	ft_strdel(buff);
	if (ft_strlen(tmp) < BUFF_SIZE)
	{
		*buff = ft_strnew(BUFF_SIZE);
		ft_strcpy(*buff, tmp);
	}
	else
		*buff = ft_strdup(tmp);
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	int				ret;
	static char		*buff = NULL;
	int				pos;

	if (!buff)
		buff = ft_strnew(BUFF_SIZE);
	if ((pos = ft_isline(&buff)) >= 0)
	{
		*line = ft_strnew(0);
		return (ft_stock(line, &buff, pos));
	}
	*line = ft_strdup(buff);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((pos = ft_isline(&buff)) != -1)
			return (ft_stock(line, &buff, pos));
		*line = ft_strjoin(*line, buff);
	}
	if (**line && ret == 0)
	{
		ft_strdel(&buff);
		return (1);
	}
	return (ret);
}
