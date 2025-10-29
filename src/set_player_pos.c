/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balhamad <balhamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:57:00 by balhamad          #+#    #+#             */
/*   Updated: 2025/10/29 13:58:50 by balhamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_player_n(t_elements *el)
{
	el->dir_x = 0;
	el->dir_y = -1;
	el->plane_x = 0.66;
	el->plane_y = 0;
}

void	set_player_s(t_elements *el)
{
	el->dir_x = 0;
	el->dir_y = 1;
	el->plane_x = -0.66;
	el->plane_y = 0;
}

void	set_player_e(t_elements *el)
{
	el->dir_x = 1;
	el->dir_y = 0;
	el->plane_x = 0;
	el->plane_y = 0.66;
}

void	set_player_w(t_elements *el)
{
	el->dir_x = -1;
	el->dir_y = 0;
	el->plane_x = 0;
	el->plane_y = -0.66;
}

void	decide_pos(t_elements *el, char c)
{
	if (c == 'N')
		set_player_n(el);
	else if (c == 'S')
		set_player_s(el);
	else if (c == 'E')
		set_player_e(el);
	else if (c == 'W')
		set_player_w(el);
}
