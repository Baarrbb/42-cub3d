/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:58:28 by marvin            #+#    #+#             */
/*   Updated: 2024/09/07 12:20:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	move_player(t_game *game, t_coor *move, int key)
{
	if (key == XK_d)
	{
		move->x = -sin(game->play_ang);
		move->y = cos(game->play_ang);
		eval_move(game, move, 1);
	}
	if (key == XK_a)
	{
		move->x = sin(game->play_ang);
		move->y = -cos(game->play_ang);
		eval_move(game, move, 0);
	}
	if (key == XK_w)
	{
		move->x = cos(game->play_ang);
		move->y = -sin(game->play_ang);
	}
	if (key == XK_s)
	{
		move->x = -cos(game->play_ang);
		move->y = sin(game->play_ang);
	}
}

static int	collision(t_coor move, t_game game)
{
	int	i;
	int	j;
	int	l;
	int	map_x;

	i = 0;
	while (i++ < 2)
	{
		game.play_x += move.x;
		game.play_y += move.y;
		j = game.play_x - 8;
		while (j++ < game.play_x + 8)
		{
			l = game.play_y - 8;
			while (l++ < game.play_y + 8)
			{
				map_x = (int)(l / IMG_SIZE);
				if (game.parsing->map[map_x][(int)(j / IMG_SIZE)] == '1'
					|| game.parsing->map[map_x][(int)(j / IMG_SIZE)] == 'D')
					return (1);
			}
		}
	}
	return (0);
}

void	key_move(t_game *game, int keycode)
{
	t_coor	move;
	double	tmp;

	move.x = 0;
	move.y = 0;
	move_player(game, &move, keycode);
	if (collision(move, *game) == 0)
	{
		game->play_x += move.x * 3;
		game->play_y += move.y * 3;
	}
	tmp = move.x;
	move.x = 0;
	if (collision(move, *game) == 0)
	{
		game->play_y += move.y * 3;
	}
	move.x = tmp;
	move.y = 0;
	if (collision(move, *game) == 0)
	{
		game->play_x += move.x * 3;
	}
}
