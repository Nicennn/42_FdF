/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrestey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 11:17:47 by rcrestey          #+#    #+#             */
/*   Updated: 2019/03/17 12:39:13 by rcrestey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int		isfdf(char *file)
{
	int		i;

	i = 0;
	while (file[i])
		i++;
	i--;
	while (i >= 0 && file[i] && file[i] != '.')
		i--;
	if (file[i] == '.')
		if (!ft_strcmp(file + i, ".fdf"))
			return (0);
	return (1);
}

static void		ft_lfree(t_lst *list)
{
	int		i;
	t_lst	*tmp;

	while (list)
	{
		i = -1;
		while (list && list->tab[++i])
			free(list->tab[i]);
		free(list->tab);
		tmp = list;
		list = list->next;
		free(tmp);
	}
	free(list);
}

static int		format(char **split, int fd)
{
	int		i;

	i = -1;
	if (!split[0])
		return (1);
	while (split[++i])
	{
		if (!ft_isdigit(split[i][0]) && split[i][0] != 45 && split[i][0] != 43)
		{
			close(fd);
			return (1);
		}
		if (ft_atoi(split[i]) > 100)
			return (1);
	}
	return (0);
}

static t_lst	*ft_check(char *file)
{
	int		fd;
	char	*line;
	char	**split;
	int		i;
	t_lst	*list;

	list = NULL;
	i = 1;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	if (isfdf(file))
		return (NULL);
	while (get_next_line(fd, &line) > 0 && (i++))
	{
		if (!*line)
			return (NULL);
		ft_ladd(&list, ft_lnew(split = ft_strsplit(line, ' ')));
		free(line);
		if (format(split, fd))
			return (NULL);
	}
	if (i < 3)
		return (NULL);
	free(line);
	return (close(fd) == -1 ? NULL : list);
}

t_point			*ft_checker(char *file)
{
	t_lst	*list;
	t_lst	*tmp;
	t_point	*point;
	int		x;
	int		y;

	point = NULL;
	if (!(list = ft_check(file)))
	{
		ft_putendl("file error, please recheck your file");
		ft_lfree(list);
		return (NULL);
	}
	tmp = list;
	y = -1;
	while (tmp)
	{
		y++;
		x = -1;
		while (tmp->tab[++x])
			ft_padd(&point, ft_pnew(x, y, ft_atoi(tmp->tab[x])));
		tmp = tmp->next;
	}
	ft_lfree(list);
	return (point);
}
