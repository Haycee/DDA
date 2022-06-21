/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:32:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/21 15:26:06 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The main.c file is where we :
	- initialize our data structure,
	- get the specifications,
*/

/*
	main.c
	get_map.c
	get_rgb_code_int_tabs.c
	parse_config_lines.c
	movement.c 						!
	key_press.c
	h_prob_manager.c
	render_game.c
	render_manager.c
	render_mini_map.c
	render_utils.c
	texture_utils.c
	v_probe_manager.c
	calcule_distance.c
	check_collision.c
	pixel_put.c
	window_manager.c

*/

#include "main.h"

int	main(int ac, char **av)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(data));
	config_parser(ac, av, &data);
	data.map.cell_size = 64;
	window_manager(&data);
	init_img(&data, &data.config, &data.mini_map, &data.walls);
	init_player(&data, &data.player, &data.config);
	init_ray_tab(&data);
	render_manager(&data, &data.win);
	mlx_hook(data.win.edge, 2, 0, key_press, &data);
	mlx_loop(data.win.mlx);
	exit (0);
}
