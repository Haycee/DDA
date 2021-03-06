/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_manager.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:24:53 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/30 17:25:09 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_MANAGER_H
# define RENDER_MANAGER_H

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/*	render_manager/dda_algorithm_utils.c									  */
int		get_ray_orientation(t_player *player, double ray_angle);
void	get_probes_len(t_player *player, t_probe *h_probe, t_probe *v_probe);
void	update_ray(t_ray *ray, double ray_angle, t_probe *h_probe, t_probe *v_probe);

/*	render_manager/dda_algorithm.c											  */
void	dda_algorithm(t_data *data, double ray_angle, int column_i);

/*	render_manager/h_probe_manager.c								  */
void	init_h_probe(t_map *map, t_player *player, double ray_angle, t_probe *h_probe);
void	find_h_probe_wall_hit(t_data *data, t_win *win, t_probe *h_probe);

/*	render_manager/ray_casting.c											  */
void	ray_casting(t_data *data);

/*	render_manager/render_game.c											  */
void	render_game(t_data *data, t_player *player, t_ray *ray_tab);

/*	render_manager/render_manager.c											  */
void	render_manager(t_data *data, t_win *win);

/*	render_manager/render_mini_map.c										  */
void	render_mini_map(t_data *data);
void	render_background(t_data *data);
void	render_walls_and_tiles(t_data *data, int x, int y);
void	render_player(t_data *data);

/*	render_manager/render_utils.c											  */
int     render_rect(t_data *data, t_img *render, t_rect rect);
int	    render_line(t_data *data, t_img *render, t_line line);
int     render_circle(t_data *data, t_img *render, t_circle circle);
int		get_pixel_color_from_texture(t_texture *texture, t_coord *coord);

/*	render_manager/texture_utils.c									  */
t_texture	get_texture(t_data *data, int i);

/*	render_manager/v_probe_manager.c									  */
void	init_v_probe(t_map *map, t_player *player, double ray_angle, t_probe *v_probe);
void	find_v_probe_wall_hit(t_data *data, t_win *win, t_probe *v_probe);

#endif