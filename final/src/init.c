/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:31:31 by balhamad          #+#    #+#             */
/*   Updated: 2025/10/19 20:16:59 by balhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_textures	*init_textures()
{
	t_textures *t = malloc(sizeof(t_textures));
	t->east = NULL;
	t->west = NULL;
	t->north = NULL;
	t->south = NULL;
	return (t);
}

int init_elements(t_elements *el)
{
	(el)->map_size = 0;
	(el)->C = NULL;
	(el)->F = NULL;
	(el)->NO = NULL;
	(el)->WE = NULL;
	(el)->EA = NULL;
	(el)->SO = NULL;
	(el)->map = NULL;
	(el)->CB = 0;
	(el)->pl_flag = 0;
	(el)->copy_map = NULL;
	(el)->map_size = 0;
	el->textures = init_textures();
	return 1;
}
int init_window(t_elements *el)
{
	el->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "HELL", false);
	if (!el->mlx)
	{
		ft_printf("Error\nFailed to initialize mlx\n");
		return (-1);
	}
	el->window = mlx_new_image(el->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!el->window)
	{
		ft_printf("Error\nFailed to create image\n");
		return (-1);
	}
	if (mlx_image_to_window(el->mlx, el->window, 0, 0) < 0)
	{
		ft_printf("Error\nFailed to put image to window\n");
		return (-1);
	}
	return (1);
}
void	ceiling_floor(t_elements *el,int x)
{
	uint32_t color_c;
	uint32_t color_f;
	int y;

	y = 0;
	color_c = (el->CR << 24) | (el->CG << 16) | (el->CB << 8)|255;
	color_f = (el->FR << 24) | (el->FG << 16) | (el->FB << 8)|255;
	while(y < el->wall_start)
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

mlx_texture_t *decide_dir(t_elements *el)
{
	if (el->side == 0 && el->raydir_x > 0)
    	return(el->textures->west);
	else if (el->side == 0 && el->raydir_x < 0)
	    return(el->textures->east);
	else if (el->side == 1 && el->raydir_y > 0)
	   return (el->textures->north);
	else
	    return (el->textures->south);
}
// void draw_textured_wall(t_elements *el,int x)
// {
// 	mlx_texture_t *tex;
// 	double wallX;

// 	tex = decide_dir(el);
// 	if (el->side == 0)
// 	    wallX = el->pos_y + el->truewalldist * el->raydir_y;
// 	else
// 	    wallX = el->pos_x + el->truewalldist * el->raydir_x;
// 	wallX -= floor(wallX);
// 	int texX = (int)(wallX * (double)(tex->width));
// 	if (el->side == 0 && el->raydir_x > 0)
// 	    texX = tex->width - texX - 1;
// 	if (el->side == 1 && el->raydir_y < 0)
// 	    texX = tex->width - texX - 1;
// 	double step = tex->height / el->wall_hight;
// 	double texPos = (el->wall_start - SCREEN_HEIGHT / 2 + el->wall_hight / 2) * step;
// 	for (int y = el->wall_start; y < el->wall_end; y++)
// 	{
// 	    int texY = (int)texPos & (tex->height - 1);
// 	    texPos += step;
// 	    int texIndex = (texY * tex->width + texX) * 4;
// 	    unsigned char r = tex->pixels[texIndex + 0];
// 	    unsigned char g = tex->pixels[texIndex + 1];
// 	    unsigned char b = tex->pixels[texIndex + 2];
// 	    unsigned char a = tex->pixels[texIndex + 3];
// 	    uint32_t color = (r << 24) | (g << 16) | (b << 8) | a;
// 	    mlx_put_pixel(el->window, x, y, color);
// 	}

// }
static int get_tex_x(t_elements * el, mlx_texture_t * tex)
{
	double wallX;
	int texX;

	if (el->side == 0)
		wallX = el->pos_y + el->truewalldist * el->raydir_y;
	else
		wallX = el->pos_x + el->truewalldist * el->raydir_x;
	wallX -= floor(wallX);

	texX = (int)(wallX * (double)(tex->width));
	if ((el->side == 0 && el->raydir_x > 0) || (el->side == 1 && el->raydir_y < 0))
		texX = tex->width - texX - 1;

	return (texX);
}

static uint32_t get_tex_color(mlx_texture_t * tex, int texX, int texY)
{
	int texIndex;

	texIndex = (texY * tex->width + texX) * 4;
	return ((tex->pixels[texIndex + 0] << 24) | (tex->pixels[texIndex + 1] << 16) | (tex->pixels[texIndex + 2] << 8) | tex->pixels[texIndex + 3]);
}
void draw_textured_wall(t_elements * el, int x)
{
	mlx_texture_t *tex;
	int texX;
	double step;
	double texPos;
	int y;

	tex = decide_dir(el);
	texX = get_tex_x(el, tex);
	step = tex->height / el->wall_hight;
	texPos = (el->wall_start - SCREEN_HEIGHT / 2 + el->wall_hight / 2) * step;
	y = el->wall_start;
	while (y < el->wall_end)
	{
		int texY;
		uint32_t color;
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
	double old_dir_x;
	double old_plane_x;

	old_dir_x = el->dir_x;
	old_plane_x = el->plane_x;
	if (mlx_is_key_down(el->mlx, MLX_KEY_LEFT))
	{
		el->dir_x = el->dir_x * cos(-ROT_SPEED) - el->dir_y * sin(-ROT_SPEED);
		el->dir_y = old_dir_x * sin(-ROT_SPEED) + el->dir_y * cos(-ROT_SPEED);
		el->plane_x = el->plane_x * cos(-ROT_SPEED) - el->plane_y * sin(-ROT_SPEED);
		el->plane_y = old_plane_x * sin(-ROT_SPEED) + el->plane_y * cos(-ROT_SPEED);
	}
	else if (mlx_is_key_down(el->mlx, MLX_KEY_RIGHT))
	{
		el->dir_x = el->dir_x * cos(ROT_SPEED) - el->dir_y * sin(ROT_SPEED);
		el->dir_y = old_dir_x * sin(ROT_SPEED) + el->dir_y * cos(ROT_SPEED);
		el->plane_x = el->plane_x * cos(ROT_SPEED) - el->plane_y * sin(ROT_SPEED);
		el->plane_y = old_plane_x * sin(ROT_SPEED) + el->plane_y * cos(ROT_SPEED);
	}
}
void cursor_hook(double xpos, double ypos, void *param)
{
	(void)ypos;
	t_elements *el = (t_elements *)param;
	double rot;
	double old_dir_x;
	double old_plane_x;
	static double last_x = -1;
	double dx;
	
	old_dir_x = el->dir_x;
	old_plane_x = el->plane_x;
	if (last_x < 0)
		last_x = xpos;
	dx = xpos - last_x;
	rot = dx * MOUSE_SENSITIVITY;
	el->dir_x = el->dir_x * cos(rot) - el->dir_y * sin(rot);
	el->dir_y = old_dir_x * sin(rot) + el->dir_y * cos(rot);
	el->plane_x = el->plane_x * cos(rot) - el->plane_y * sin(rot);
	el->plane_y = old_plane_x * sin(rot) + el->plane_y * cos(rot);
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
	mlx_cursor_hook(el->mlx, cursor_hook, el);
	mlx_loop_hook(el->mlx, keyhook, el);
	mlx_loop_hook(el->mlx, render, el);
	mlx_loop(el->mlx);
	mlx_terminate(el->mlx);
}
