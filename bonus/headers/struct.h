/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:20:25 by marvin            #+#    #+#             */
/*   Updated: 2024/09/03 23:35:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# ifndef NB_ANIM
#  define NB_ANIM 24
# endif

typedef struct s_file
{
	char			*line;
	struct s_file	*next;
}	t_file;

typedef struct s_parse
{
	char	**map;
	char	**map_copy;

	char	*north;
	char	*south;
	char	*east;
	char	*west;

	t_file	*init;

	int		f_red;
	int		f_green;
	int		f_blue;

	int		c_red;
	int		c_green;
	int		c_blue;

	int		player_position;

	int		len_y;
}	t_parse;

typedef struct s_coor
{
	double	x;
	double	y;
}	t_coor;

typedef struct s_mlx
{
	void	*img;
	void	*addr;

	int		bpp;
	int		l_len;
	int		endian;
}	t_mlx;

typedef struct s_data
{
	int				y;
	int				i;
	int				j;
	unsigned int	color;
	int				offset;
	int				flag;
	t_mlx			text;
	char			**copy_map;
	int				index;
	int				index_j;
}	t_data;

typedef struct s_key
{
	int	l_view;
	int	r_view;
	int	l_move;
	int	r_move;
	int	f_move;
	int	b_move;
}	t_key;

typedef struct s_shoot
{
	t_coor	hit_shoot;
	int		flag;
	int		slice;
	int		cross_r;
	int		cross_l;

	int		dwin_x;
	int		fwin_x;

	t_coor	pos_check;

	t_coor	dec;

	int		size;
}	t_shoot;

typedef struct s_door
{
	int				id;
	int				startx;
	int				starty;
	int				endx;
	int				endy;
	int				px;
	int				py;
	int				endpx;
	int				endpy;
	long			time;
	int				open;
	struct s_door	*next;
}	t_door;

typedef struct s_color
{
	unsigned int	r;
	unsigned int	b;
	unsigned int	g;
	unsigned int	t;
}	t_color;

typedef struct s_mouse {
	int	press;
	int	x_press;
}	t_mouse;

typedef struct s_game
{
	t_parse	*parsing;

	void	*mlx;
	void	*win;

	t_mlx	text[4];
	t_mlx	img;

	int		floor;
	int		ceiling;

	t_coor	hit_wall;
	t_coor	hit_mat;

	double	play_x;
	double	play_y;
	double	play_ang;
	double	fov_ang;
	double	ray_ang;
	double	distance;

	t_mlx	shoot[NB_ANIM];
	int		tir;
	int		render;
	t_mlx	pistol[5];
	int		p;
	int		p_index;

	t_shoot	var;

	t_key	key_event;
	int		index_anim;

	double	intensity;
	int		minimap_size;
	int		light;
	int		fog;

	t_door	*doors;
	t_mlx	door;
	double	v_inter;
	long	start_timer;

	t_mouse	mouse;

}	t_game;

#endif