/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:07:37 by balhamad          #+#    #+#             */
/*   Updated: 2025/10/19 16:50:02 by balhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H

#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "../libft/libft.h"
#include "../MLX42/MLX42/include/MLX42/MLX42.h"
#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 600
#define MOVE_SPEED 0.1
#define ROT_SPEED 0.05

typedef struct s_textures
{
	mlx_texture_t *north;
	mlx_texture_t *south;
	mlx_texture_t *west;
	mlx_texture_t *east;

} t_textures;

typedef struct s_elements
{
	struct s_textures *textures;
	void *mlx;
	mlx_image_t *window;
	int fd;
	int map_size;
	int pl_flag;
	char *NO;
	char *SO;
	char *WE;
	char *EA;
	char *F;
	char *C;
	int FR;
	int FG;
	int FB;
	int CR;
	int CG;
	int CB;
	char **map;
	char **copy_map;
	float pos_x;
	float pos_y;
	double dir_x;
	double dir_y;
	int map_x;
	int map_y;
	int step_x;
	int step_y;
	int side;
	int exit_flag;
	double delta_dist_x;
	double delta_dist_y;
	double truewalldist;
	int wall_start;
	int wall_end;
	double wall_hight;
	double plane_x;
	double plane_y;
	double side_dist_x;
	double side_dist_y;
	double raydir_x;
	double raydir_y;
	double camera_x;
} t_elements;

void exit_all(t_elements *elements);
int check_extention(char *file);
void free_2d_array(char **arr);
int get_pos(t_elements *el);
int check_lines(t_elements *elements, char *file);
void free_2d_array(char **arr);
int map_exit(char ***map, t_elements *el);
int check_mapline(t_elements *el,char *line);
void remove_nl(char *str);
int save_mapline(t_elements *el, char *line);
int map_validation(t_elements *elements, int fd, int count, char *line);
int copy_the_map(t_elements *el);
void flood_fill(t_elements *info, int x, int y);
int solveable(t_elements *info);
void decide_pos(t_elements *el, char c);
void free_textures(t_elements *el);
void free_elements(t_elements *el);
int init_elements(t_elements *el);
t_textures *init_textures();
int init_window(t_elements *el);
void render(void *param);
void run(t_elements *el);
void ini_ray_var(t_elements *el, int x);
void find_side_dist(t_elements *el);
int start_dda(t_elements *el);
void prep_for_walls(t_elements *el);
#endif
