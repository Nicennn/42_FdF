/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrestey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 19:31:45 by rcrestey          #+#    #+#             */
/*   Updated: 2019/03/16 22:29:40 by rcrestey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strindexof(const char *str, const char *find)
{
	char		*ptr;

	if (str == NULL || find == NULL)
		return (-1);
	if (!(ptr = ft_strstr(str, find)))
		return (-1);
	return (ptr - str);
}

t_buffer	*ft_getbuffer(t_buffer **root, int fd)
{
	t_buffer	*tmp;

	tmp = *root;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = malloc(sizeof(*tmp))))
		return (NULL);
	ft_bzero(tmp, sizeof(*tmp));
	tmp->fd = fd;
	tmp->next = *root;
	*root = tmp;
	return (tmp);
}

char		*ft_bufferjoin(char *line, char *buffer)
{
	char		*tmp;

	if (!(tmp = ft_strjoin(line, buffer)))
		return (NULL);
	ft_strdel(&line);
	return (tmp);
}

int			ft_finish(t_buffer *target, char **line, int ret, char *buffer)
{
	if (ret == -1)
	{
		ft_bzero(target->buffer, BUFF_SIZE);
		return (ft_strlen(*line) > 0 ? SUCCESS : FINISH);
	}
	*(buffer + ret) = '\0';
	if (!(*line = ft_bufferjoin(*line, buffer)))
		return (ERROR);
	ft_bzero(target->buffer, BUFF_SIZE);
	ft_memmove(target->buffer, buffer + ret + 1, BUFF_SIZE - ret);
	return (SUCCESS);
}

int			get_next_line(const int fd, char **line)
{
	static t_buffer	*root;
	char			buffer[BUFF_SIZE + 1];
	t_buffer		*target;
	int				ret;
	int				i;

	if (fd < 0 || line == NULL)
		return (ERROR);
	if (!(target = ft_getbuffer(&root, fd)))
		return (ERROR);
	if (!(*line = ft_strnew(0)))
		return (ERROR);
	ret = 1;
	ft_strcpy(ft_memset(buffer, 0, BUFF_SIZE + 1), target->buffer);
	while ((i = ft_strindexof(buffer, "\n")) == -1 && ret > 0)
	{
		if (!(*line = ft_bufferjoin(*line, buffer)))
			return (ERROR);
		ft_bzero(buffer, BUFF_SIZE + 1);
		if ((ret = read(fd, buffer, BUFF_SIZE)) == -1)
			return (ERROR);
	}
	return (ft_finish(target, line, ret == 0 ? -1 : i, buffer));
}
