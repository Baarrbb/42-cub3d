/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:09:05 by marvin            #+#    #+#             */
/*   Updated: 2024/09/01 00:18:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

/***************************************************/
/*                   PARSING                       */
/***************************************************/
/**/
/*                   PARSING.C                     */
t_parse			*parsing(char **argv);
int				trim_backslashn(t_file *init);

/*                   PARSING_UTILS.C               */
void			check_end_parse(t_parse *parsed, t_file *init, int index);
int				ft_inisize(t_file *lst);
t_parse			*initalizeparse(void);
int				skip_nb_and_spaces(int index, t_parse *parsed, t_file *init);
int				ft_strlen_matrice(char **map);

/*                   PARSING_UTILS2.C                */
int				file_len(t_file *file);
void			empty_init(t_file *init);
int				check_border(char **copy_map);
int				line_copy(t_data *d, int i, int j, char **map);
void			handle_error_pars(char *s, t_file *file);

/*                   PARSING_CHARS.C               */
void			fill_struct(t_parse *parsed, t_file *init);

/*                   PARSING_STRUCT.C                 */
void			get_cubfile(t_file **init, char *file);

/*                   PARSING_MAP.C                 */
int				parsing_map(t_parse *parsed);
int				check_correct_walls(char **map, int x, int y, int type);

/*                   RIGHT_SIDE.C                  */
int				find_longest_line(char **map, int *i);
char			**copy_right_with_spaces(char **map, int i, int j);
int				handle_right(char **copy_map);

/*                   PARSING_MAP2.C                */
int				check_inside(t_parse *parsed, char **copy_map);

/*                   PARSING_SANITIZE.C            */
void			free_struct(t_file *init);
void			errorfunctionparse(t_parse *parsed, char *message);
void			free_map(char **map);
void			free_parse(t_parse *parsed);

/*					 PARSING_CHARS_UTILS.C			*/
int				fill_util(t_parse *parsed, t_file *init, int *index);
int				fill_utils(t_parse *parsed, t_file *init, int *index);

#endif