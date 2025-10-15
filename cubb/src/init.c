/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:51:51 by balhamad          #+#    #+#             */
/*   Updated: 2025/10/15 17:43:00 by tabuayya         ###   ########.fr       */
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
void draw_textured_wall(t_elements *el,int x)
{
	mlx_texture_t *tex;
	double wallX;
	tex = decide_dir(el);
	if (el->side == 0)
	    wallX = el->pos_y + el->truewalldist * el->raydir_y;
	else
	    wallX = el->pos_x + el->truewalldist * el->raydir_x;
	wallX -= floor(wallX);
	int texX = (int)(wallX * (double)(tex->width));
	if (el->side == 0 && el->raydir_x > 0)
	    texX = tex->width - texX - 1;
	if (el->side == 1 && el->raydir_y < 0)
	    texX = tex->width - texX - 1;
	double step = 1.0 * tex->height / el->wall_hight;
	double texPos = (el->wall_start - SCREEN_HEIGHT / 2 + el->wall_hight / 2) * step;
	for (int y = el->wall_start; y < el->wall_end; y++)
	{
	    int texY = (int)texPos & (tex->height - 1);
	    texPos += step;

	    int texIndex = (texY * tex->width + texX) * 4;

	    unsigned char r = tex->pixels[texIndex + 0];
	    unsigned char g = tex->pixels[texIndex + 1];
	    unsigned char b = tex->pixels[texIndex + 2];
	    unsigned char a = tex->pixels[texIndex + 3];

	    uint32_t color = (r << 24) | (g << 16) | (b << 8) | a;

	    mlx_put_pixel(el->window, x, y, color);
	}

}
void move_forword(t_elements *el)
{
	double new_x;
	double new_y;

	new_x=el->pos_x;
	new_y=el->pos_y;
	new_x += el->dir_x * MOVE_SPEED;
	new_y += el->dir_y * MOVE_SPEED;
	if(el->map[(int)new_y][(int)el->pos_x] != '1')
		el->pos_y = new_y;
	if(el->map[(int)el->pos_y][(int)new_x] != '1')
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
	if(el->map[(int)new_y][(int)el->pos_x] != '1')
		el->pos_y = new_y;
	if(el->map[(int)el->pos_y][(int)new_x] != '1')
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
	if(el->map[(int)new_y][(int)el->pos_x] != '1')
		el->pos_y = new_y;
	if(el->map[(int)el->pos_y][(int)new_x] != '1')
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
	if(el->map[(int)new_y][(int)el->pos_x] != '1')
		el->pos_y = new_y;
	if(el->map[(int)el->pos_y][(int)new_x] != '1')
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
	if (mlx_is_key_down(el->mlx, MLX_KEY_RIGHT))
	{
		el->dir_x = el->dir_x * cos(ROT_SPEED) - el->dir_y * sin(ROT_SPEED);
		el->dir_y = old_dir_x * sin(ROT_SPEED) + el->dir_y * cos(ROT_SPEED);
		el->plane_x = el->plane_x * cos(ROT_SPEED) - el->plane_y * sin(ROT_SPEED);
		el->plane_y = old_plane_x * sin(ROT_SPEED) + el->plane_y * cos(ROT_SPEED);
	}
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
	init_window(el);
	mlx_loop_hook(el->mlx,keyhook,el);
	mlx_loop_hook(el->mlx,render,el);
	mlx_loop(el->mlx);
	mlx_terminate(el->mlx);
}
