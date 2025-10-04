/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_doors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoong <nyoong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:14:57 by nyoong            #+#    #+#             */
/*   Updated: 2025/09/26 18:15:06 by nyoong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	update_door_state(t_door *d)
{
	if (d->opening == 1 && d->state < DOOR_MAX)
		d->state += DOOR_SPEED;
	else if (d->opening == -1 && d->state > DOOR_MIN)
		d->state -= DOOR_SPEED;
	if (d->state >= DOOR_MAX)
	{
		d->state = DOOR_MAX;
		d->opening = 0;
	}
	if (d->state <= DOOR_MIN)
	{
		d->state = DOOR_MIN;
		d->opening = 0;
	}
}

static void	update_door_anim(t_door *d)
{
	int	idx;

	idx = (int)(d->state * (d->anim.frame_count - 1) + 0.5);
	if (idx < 0)
		idx = 0;
	if (idx >= d->anim.frame_count)
		idx = d->anim.frame_count - 1;
	d->anim.current = idx;
}

void	update_doors(t_game *game)
{
	int		i;
	t_door	*d;

	i = 0;
	while (i < game->door_count)
	{
		d = &game->doors[i];
		update_door_state(d);
		update_door_anim(d);
		i++;
	}
}
