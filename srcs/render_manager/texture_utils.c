/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:26:11 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/21 15:34:05 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_texture	get_north_texture(t_data *data, int i);
t_texture	get_south_texture(t_data *data, int i);
t_texture	get_east_texture(t_data *data, int i);
t_texture	get_west_texture(t_data *data, int i);

t_texture	get_texture(t_data *data, int i)
{
	if (data->player.orientation == 'N')
	{
		return(get_north_texture(data, i));
	}
	else if (data->player.orientation == 'S')
	{
		return(get_south_texture(data, i));
	}
	else if (data->player.orientation == 'E')
	{
		return(get_east_texture(data, i));
	}
	else if (data->player.orientation == 'W')
	{
		return(get_west_texture(data, i));
	}
	return (data->so_tex);
}

t_texture	get_north_texture(t_data *data, int i)
{
	if (data->ray_tab[i].grid_hit == HORIZONTAL)
		return (data->so_tex);
	else
	{
		if (data->player.x > data->ray_tab[i].wall_hit_x)
			return (data->ea_tex);
		else
			return (data->we_tex);
	}
}

t_texture	get_south_texture(t_data *data, int i)
{
	if (data->ray_tab[i].grid_hit == HORIZONTAL)
		return (data->no_tex);
	else
	{
		if (data->player.x < data->ray_tab[i].wall_hit_x)
			return (data->we_tex);
		else
			return (data->ea_tex);
	}
}

t_texture	get_east_texture(t_data *data, int i)
{
	if (data->ray_tab[i].grid_hit == VERTICAL)
		return (data->we_tex);
	else
	{
		if (data->player.y > data->ray_tab[i].wall_hit_y)
			return (data->so_tex);
		else
			return (data->no_tex);
	}
}

t_texture	get_west_texture(t_data *data, int i)
{
	if (data->ray_tab[i].grid_hit == VERTICAL)
		return (data->ea_tex);
	else
	{
		if (data->player.y < data->ray_tab[i].wall_hit_y)
			return (data->no_tex);
		else
			return (data->so_tex);
	}
}
