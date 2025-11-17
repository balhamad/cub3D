/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:43:38 by balhamad          #+#    #+#             */
/*   Updated: 2025/11/02 17:52:10 by balhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ceiling_floor(t_elements *el, int x)
{
	int			y;
	uint32_t	color_c;
	uint32_t	color_f;

	y = 0;
	color_c = ((uint32_t)el->cr << 24)
		| ((uint32_t)el->cg << 16)
		| ((uint32_t)el->cb << 8)
		| 255;
	color_f = ((uint32_t)el->fr << 24)
		| ((uint32_t)el->fg << 16)
		| ((uint32_t)el->fb << 8)
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

void	draw_textured_wall(t_elements *el, int x)
{
	mlx_texture_t	*tex;
	double			step;
	double			texpos;
	uint32_t		color;

	tex = decide_dir(el);
	el->texx = get_tex_x(el, tex);
	step = (double)tex->height / (double)el->wall_hight;
	texpos = (el->wall_start - SCREEN_HEIGHT / 2
			+ el->wall_hight / 2) * step;
	el->y = el->wall_start;
	while (el->y < el->wall_end)
	{
		el->texy = (int)texpos & (tex->height - 1);
		color = get_tex_color(tex, el->texx, el->texy);
		mlx_put_pixel(el->window, x, el->y, color);
		texpos += step;
		el->y++;
	}
}
