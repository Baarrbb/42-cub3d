/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_chars_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:37:54 by marvin            #+#    #+#             */
/*   Updated: 2024/09/07 12:24:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	fill_utils(t_parse *parsed, t_file *init, int *index)
{
	parsed->c_red = ft_atoi(&init->line[*index]);
	if (parsed->c_red > 255 || parsed->c_red < 0 \
		|| !ft_isdigit(init->line[*index]))
		errorfunctionparse(parsed, "Wrong red code\n");
	*index = skip_nb_and_spaces(*index, parsed, init);
	parsed->c_green = ft_atoi(&init->line[*index]);
	if (parsed->c_green > 255 || parsed->c_green < 0 \
		|| !ft_isdigit(init->line[*index]))
		errorfunctionparse(parsed, "Wrong green code\n");
	*index = skip_nb_and_spaces(*index, parsed, init);
	parsed->c_blue = ft_atoi(&init->line[*index]);
	if (parsed->c_blue > 255 || parsed->c_blue < 0 \
		|| !ft_isdigit(init->line[*index]))
		errorfunctionparse(parsed, "Wrong blue code\n");
	return (0);
}

int	fill_util(t_parse *parsed, t_file *init, int *index)
{
	parsed->f_red = ft_atoi(&init->line[*index]);
	if (parsed->f_red > 255 || parsed->f_red < 0 \
		|| !ft_isdigit(init->line[*index]))
		errorfunctionparse(parsed, "Wrong red code\n");
	*index = skip_nb_and_spaces(*index, parsed, init);
	parsed->f_green = ft_atoi(&init->line[*index]);
	if (parsed->f_green > 255 || parsed->f_green < 0 \
		|| !ft_isdigit(init->line[*index]))
		errorfunctionparse(parsed, "Wrong green code\n");
	*index = skip_nb_and_spaces(*index, parsed, init);
	parsed->f_blue = ft_atoi(&init->line[*index]);
	if (parsed->f_blue > 255 || parsed->f_blue < 0 \
		|| !ft_isdigit(init->line[*index]))
		errorfunctionparse(parsed, "Wrong blue code\n");
	return (0);
}
