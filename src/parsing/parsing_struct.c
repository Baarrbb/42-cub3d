/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:26:25 by marvin            #+#    #+#             */
/*   Updated: 2024/09/07 12:24:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_file	*lstlast(t_file *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

static t_file	*lstnew(char *line)
{
	t_file	*stru;

	stru = (t_file *)malloc(sizeof(t_file));
	if (stru == NULL)
		return (NULL);
	stru->line = line;
	stru->next = NULL;
	return (stru);
}

static void	lstadd_back(t_file **lst, t_file *new)
{
	t_file	*pointer;

	if (lst == NULL || new == NULL)
		return ;
	pointer = *lst;
	if (*lst == NULL)
		(*lst) = new;
	else
	{
		pointer = lstlast(*lst);
		pointer->next = new;
	}
}

void	get_cubfile(t_file **init, char *file)
{
	int		fd;
	t_file	*new;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		handle_error_pars("Wrong filename\n", *init);
	line = get_next_line(fd);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
		new = lstnew(line);
		lstadd_back(init, new);
		line = get_next_line(fd);
	}
	if (errno != 0)
		handle_error_pars("get_next_line() failed\n", *init);
	close(fd);
}
