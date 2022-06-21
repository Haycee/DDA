/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:36:07 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/21 14:36:40 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The render_manager.c file is where we :
	- initialize the mini_map image.
	- add pixels to the image that correspond to:
		- the map
		- the player position
		- the rays
	- put the mini_map imge to the window
*/

#include "main.h"

void	render_manager(t_data *data, t_win *win)
{
	ray_casting(data);
	render_game(data, &data->player, data->ray_tab);
	render_mini_map(data);
	mlx_put_image_to_window(win->mlx, win->edge, data->walls.ptr, 0, 0);
}
