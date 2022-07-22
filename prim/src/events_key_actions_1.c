/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_key_actions_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:28:30 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/07/19 04:26:52 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	key_0(t_data *prm, int keycode)
{
	(void)keycode;
	ft_update_zoom_level(prm, prm->zoom_init[0], prm->zoom_init[1],
		prm->zoom_init[2]);
	prm->zoom_total = 1;
	prm->zoom_now = 1;
	prm->coord[0] = prm->win_width / 2;
	prm->coord[1] = prm->win_height / 2;
	ft_coord2cmplx(prm);
	ft_zoom(prm);
	ft_image_update(prm);
	ft_assign_coord(prm, prm->img_width / 2, prm->img_height / 2);
	return (0);
}

int	key_1to6(t_data *prm, int keycode)
{
	prm->clr_md = keycode - 48;
	if (keycode >= '1' && keycode <= '3')
	{
		prm->clr_md1[prm->clr_md]
			= !prm->clr_md1[prm->clr_md];
	}
	ft_image_update(prm);
	ft_assign_coord(prm, prm->img_width / 2, prm->img_height / 2);
	return (0);
}

int	key_7(t_data *prm, int keycode)
{
	prm->clr_md = keycode - 48;
	ft_image_update(prm);
	ft_assign_coord(prm, prm->img_width / 2, prm->img_height / 2);
	return (0);
}

int	key_rsl(t_data *prm, int keycode)
{
	prm->mx_itr += (keycode == '-') * -prm->inc_itr
		+ (keycode == '=') * prm->inc_itr;
	prm->mx_itr = prm->mx_itr;
	ft_printf("mx_itr = %d\n", prm->mx_itr);
	ft_image_update(prm);
	ft_assign_coord(prm, prm->img_width / 2, prm->img_height / 2);
	return (0);
}

int	key_arrows(t_data *prm, int keycode)
{
	int	x;
	int	y;

	x = prm->img_width / 2 + prm->img_width / 8
		* (-(keycode == ON_ARROWLEFT) + (keycode == ON_ARROWRIGHT));
	y = prm->img_height / 2 + prm->img_height / 8
		* ((keycode == ON_ARROWDOWN) - (keycode == ON_ARROWUP));
	ft_assign_coord(prm, x, y);
	prm->focus[0] = prm->cmplx[0];
	prm->focus[1] = prm->cmplx[1];
	ft_printf("center point (x10^9) : (%d, %d)\n",
		(int)(prm->cmplx[0] * prm->prtfct),
		(int)(prm->cmplx[1] * prm->prtfct));
	prm->zoom_now = 1;
	ft_zoom(prm);
	return (0);
}
