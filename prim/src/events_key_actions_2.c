/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_key_actions_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:28:30 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/07/19 03:56:45 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	key_const(t_data *prm, int keycode)
{
	if (keycode == 'j')
		prm->c[0] -= 0.01;
	else if (keycode == 'i')
		prm->c[1] += 0.01;
	else if (keycode == 'k')
		prm->c[0] += 0.01;
	else if (keycode == 'm')
		prm->c[1] -= 0.01;
	ft_printf("c(x100) = %d %c %di\n", (int)(prm->c[0] * 100),
		(prm->c[1] < 0) * '-' + (prm->c[1] >= 0) * '+',
		(int)(ft_abs(prm->c[1] * 100)));
	ft_image_update(prm);
	ft_assign_coord(prm, prm->img_width / 2, prm->img_height / 2);
	return (0);
}
