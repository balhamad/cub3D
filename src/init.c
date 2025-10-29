/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:31:31 by balhamad          #+#    #+#             */
/*   Updated: 2025/10/29 15:13:48 by balhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ceiling_floor(t_elements *el, int x)
{
    int			y;
    uint32_t	color_c;
    uint32_t	color_f;

    y = 0;
    color_c = ((uint32_t)el->CR << 24)
        | ((uint32_t)el->CG << 16)
        | ((uint32_t)el->CB << 8)
        | 255;
    color_f = ((uint32_t)el->FR << 24)
        | ((uint32_t)el->FG << 16)
        | ((uint32_t)el->FB << 8)
        | 255;
    while (y < el->wall_start)
    {
        mlx_put_pixel(el->window, x, y, color_c);
        y++;
    }
    y = el->wall_end;
    while (y < SCREEN_HEIGHT)
    {
        mlx_put_pixel(el->window, x, y, color_f);
        y++;
    }
}

mlx_texture_t	*decide_dir(t_elements *el)
{
	if (el->side == 0 && el->raydir_x > 0)
		return (el->textures->west);
	else if (el->side == 0 && el->raydir_x < 0)
		return (el->textures->east);
	else if (el->side == 1 && el->raydir_y > 0)
		return (el->textures->north);
	else
		return (el->textures->south);
}

static int	get_tex_x(t_elements *el, mlx_texture_t *tex)
{
	double	wallx;
	int		texx;

	if (el->side == 0)
		wallx = el->pos_y + el->truewalldist * el->raydir_y;
	else
		wallx = el->pos_x + el->truewalldist * el->raydir_x;
	wallx -= floor(wallx);
	texx = (int)(wallx * (double)(tex->width));
	if ((el->side == 0 && el->raydir_x <= 0)
		|| (el->side == 1 && el->raydir_y >= 0))
		texx = tex->width - texx - 1;
	return (texx);
}

static uint32_t	get_tex_color(mlx_texture_t *tex, int texX, int texY)
{
    int			texindex;
    uint32_t	r;
    uint32_t	g;
    uint32_t	b;
    uint32_t	a;

    texindex = (texY * tex->width + texX) * 4;
    r = (uint8_t)tex->pixels[texindex + 0];
    g = (uint8_t)tex->pixels[texindex + 1];
    b = (uint8_t)tex->pixels[texindex + 2];
    a = (uint8_t)tex->pixels[texindex + 3];
    return ((r << 24) | (g << 16) | (b << 8) | a);
}
void draw_textured_wall(t_elements * el, int x)
{
    mlx_texture_t	*tex;
    int				texX;
    double			step;
    double			texPos;
    int				y;
    int				texY;
    uint32_t		color;

    tex = decide_dir(el);
    texX = get_tex_x(el, tex);
    step = (double)tex->height / (double)el->wall_hight;
    texPos = (el->wall_start - SCREEN_HEIGHT / 2
            + el->wall_hight / 2) * step;
    y = el->wall_start;
    while (y < el->wall_end)
    {
        texY = (int)texPos & (tex->height - 1);
        color = get_tex_color(tex, texX, texY);
        mlx_put_pixel(el->window, x, y, color);
        texPos += step;
        y++;
    }
}

int	is_wall(t_elements *el, double x, double y)
{
	int	map_x;
	int	map_y;
	double margin;

	margin = 0.1;
	if (x < 0 || y < 0 || y >= SCREEN_HEIGHT || x >= SCREEN_WIDTH)
		return (1);
	map_x = (int)(x - margin);
	map_y = (int)(y - margin);
	if (el->map[map_y][map_x] == '1')
		return (1);
	map_x = (int)(x + margin);
	map_y = (int)(y - margin);
	if (el->map[map_y][map_x] == '1')
		return (1);
	map_x = (int)(x - margin);
	map_y = (int)(y + margin);
	if (el->map[map_y][map_x] == '1')
		return (1);
	map_x = (int)(x + margin);
	map_y = (int)(y + margin);
	if (el->map[map_y][map_x] == '1')
		return (1);
	return (0);
}

void move_forword(t_elements *el)
{
	double new_x;
	double new_y;

	new_x=el->pos_x;
	new_y=el->pos_y;
	new_x += el->dir_x * MOVE_SPEED;
	new_y += el->dir_y * MOVE_SPEED;
if (!is_wall(el, el->pos_x, new_y))
	el->pos_y = new_y;
if (!is_wall(el, new_x, el->pos_y))
	el->pos_x = new_x;
}
void move_back(t_elements *el)
{
	double new_x;
	double new_y;

	new_x=el->pos_x;
	new_y=el->pos_y;
	new_x -= el->dir_x * MOVE_SPEED;
	new_y -= el->dir_y * MOVE_SPEED;
	if (!is_wall(el, el->pos_x, new_y))
	el->pos_y = new_y;
if (!is_wall(el, new_x, el->pos_y))
	el->pos_x = new_x;
}
void move_right(t_elements *el)
{
	double new_x;
	double new_y;

	new_x=el->pos_x;
	new_y=el->pos_y;
	new_x += el->plane_x * MOVE_SPEED;
	new_y += el->plane_y * MOVE_SPEED;
	if (!is_wall(el, el->pos_x, new_y))
		el->pos_y = new_y;
	if (!is_wall(el, new_x, el->pos_y))
		el->pos_x = new_x;
}
void move_left(t_elements *el)
{
	double new_x;
	double new_y;

	new_x=el->pos_x;
	new_y=el->pos_y;
	new_x -= el->plane_x * MOVE_SPEED;
	new_y -= el->plane_y * MOVE_SPEED;

	if (!is_wall(el, el->pos_x, new_y))
		el->pos_y = new_y;
	if (!is_wall(el, new_x, el->pos_y))
		el->pos_x = new_x;
}
void move_pos(mlx_key_data_t keydata, t_elements *el)
{
	if(keydata.key == MLX_KEY_W)
		move_forword(el);
	else if(keydata.key == MLX_KEY_S)
		move_back(el);
	else if(keydata.key == MLX_KEY_D)
		move_right(el);
	else if(keydata.key == MLX_KEY_A)
		move_left(el);
}

void rotate(t_elements *el)
{
    double old_dir_x = el->dir_x;
    double old_plane_x = el->plane_x;
    double rot = 0.0;

    if (mlx_is_key_down(el->mlx, MLX_KEY_LEFT))
        rot -= ROT_SPEED;
    if (mlx_is_key_down(el->mlx, MLX_KEY_RIGHT))
        rot += ROT_SPEED;

    if (rot != 0.0)
    {
        el->dir_x = el->dir_x * cos(rot) - el->dir_y * sin(rot);
        el->dir_y = old_dir_x * sin(rot) + el->dir_y * cos(rot);
        el->plane_x = el->plane_x * cos(rot) - el->plane_y * sin(rot);
        el->plane_y = old_plane_x * sin(rot) + el->plane_y * cos(rot);
    }
}
void cursor_hook(double xpos, double ypos, void *param)
{
    (void)ypos;
    t_elements	*el = (t_elements *)param;
    double		old_dir_x;
    double		old_plane_x;
    static double	last_x = -1;
    double		dx;
    double		angle;
    double		cos_a;
    double		sin_a;

    old_dir_x = el->dir_x;
    old_plane_x = el->plane_x;
    if (last_x < 0)
        last_x = xpos;
    dx = xpos - last_x;
    angle = dx * MOUSE_SENSITIVITY;
    cos_a = cos(angle);
    sin_a = sin(angle);
    el->dir_x = el->dir_x * cos_a - el->dir_y * sin_a;
    el->dir_y = old_dir_x * sin_a + el->dir_y * cos_a;
    el->plane_x = el->plane_x * cos_a - el->plane_y * sin_a;
    el->plane_y = old_plane_x * sin_a + el->plane_y * cos_a;
    last_x = xpos;
}

void keyhook(void *param)
{
	t_elements *el = (t_elements *)param;

	if(mlx_is_key_down(el->mlx, MLX_KEY_ESCAPE))
		exit_all(el);
	if(mlx_is_key_down(el->mlx,MLX_KEY_W))
		move_forword(el);
	if(mlx_is_key_down(el->mlx,MLX_KEY_S))
		move_back(el);
	if(mlx_is_key_down(el->mlx,MLX_KEY_D))
		move_right(el);
	if(mlx_is_key_down(el->mlx,MLX_KEY_A))
		move_left(el);
	rotate(el);
}
void render(void *param)
{
	t_elements *el;
	int x;

	x = 0;
	el = (t_elements *)param;
	while(x < SCREEN_WIDTH)
	{
		ini_ray_var(el, x);
		find_side_dist(el);
		el->side = start_dda(el);
		prep_for_walls(el);
		ceiling_floor(el, x);
		draw_textured_wall(el, x);
		x++;
	}
}
void run(t_elements *el)
{
	int32_t mouse_x;
	int32_t mouse_y;

	init_window(el);
	mlx_get_mouse_pos(el->mlx, &mouse_x, &mouse_y);
	mlx_close_hook(el->mlx, exit_all, el);
	mlx_cursor_hook(el->mlx, cursor_hook, el);
	mlx_loop_hook(el->mlx, keyhook, el);
	mlx_loop_hook(el->mlx, render, el);
	mlx_loop(el->mlx);
	mlx_terminate(el->mlx);
}

