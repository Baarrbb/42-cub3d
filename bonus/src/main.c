/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:19:43 by marvin            #+#    #+#             */
/*   Updated: 2024/09/07 12:22:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	loop_fun(t_game *game)
{
	render(game);
	key_event(game);
	return (0);
}

static void	hook_event(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, press_key, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, release_key, game);
	mlx_hook(game->win, ButtonPress, ButtonPressMask, button_press, game);
	mlx_hook(game->win, ButtonRelease, ButtonReleaseMask, button_release, game);
	mlx_hook(game->win, MotionNotify, PointerMotionMask, mouse_move, game);
	mlx_loop_hook(game->mlx, &loop_fun, game);
	mlx_hook(game->win, DestroyNotify, 0, win_exit, game);
}

int	main(int ac, char **av)
{
	t_parse	*pars;
	t_game	game;

	if (ac != 2)
	{
		ft_putstr_fd(RED BOLD "Error\n" RESET "Wrong arguments\n", 2);
		ft_putstr_fd(BLUE "\nUsage : " RESET "./cub3D <filename>.cub\n", 2);
		return (1);
	}
	pars = parsing(av);
	if (parsing_map(pars))
		return (free_parse(pars), 1);
	pars->map_copy = map_copy(pars->map);
	pars->len_y = ft_strlen_matrice(pars->map);
	game_init(&game, pars);
	govalo(&game);
	ft_memset(&(game.key_event), 0, sizeof(t_key));
	hook_event(&game);
	mlx_loop(game.mlx);
	return (0);
}
