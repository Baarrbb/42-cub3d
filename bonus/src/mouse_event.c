/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 23:44:41 by marvin            #+#    #+#             */
/*   Updated: 2024/09/04 00:10:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	button_press(int button, int x, int y, t_game *game)
{
	(void)y;
	if (button == 1)
	{
		game->mouse.x_press = x;
		game->mouse.press = 1;
	}
	if (button == 3)
		shoot(game);
	return (0);
}

int	button_release(int button, int x, int y, t_game *game)
{
	(void)y;
	(void)x;
	if (button == 1)
		game->mouse.press = 0;
	return (0);
}

int	mouse_move(int x, int y, t_game *game)
{
	int		diff;
	float	sensitivity;

	(void)y;
	if (game->render)
		game->mouse.press = 0;
	if (game->mouse.press == 1)
	{
		diff = game->mouse.x_press - x;
		sensitivity = 0.005f;
		game->play_ang += diff * sensitivity;
		check_max_trigo(&game->play_ang);
		game->mouse.x_press = x;
	}
	return (0);
}
