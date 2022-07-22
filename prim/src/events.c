/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 05:21:08 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/07/19 03:55:29 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	key_hook(int keycode, t_data *prm)
{
	if (keycode == '0')
		key_0(prm, keycode);
	else if (keycode >= '1' && keycode <= '6' && prm->set != 3)
		key_1to6(prm, keycode);
	else if (keycode == '7' && prm->set != 3)
		key_7(prm, keycode);
	else if (keycode == '-' || keycode == '=')
		key_rsl(prm, keycode);
	else if (keycode == ON_DESTROY)
		ft_exit(prm);
	else if (keycode == 'j' || keycode == 'k'
		|| keycode == 'i' || keycode == 'm')
		key_const(prm, keycode);
	else if (keycode >= ON_ARROWLEFT && keycode <= ON_ARROWDOWN)
		key_arrows(prm, keycode);
	else if (keycode >= 65429 && keycode <= 65437)
		key_thsv(prm, keycode);
	else if (keycode == 65451 || keycode == 65453)
		key_thsv_2(prm, keycode);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *prm)
{
	if (keycode == ON_MOUSELEFTCLICK || keycode == ON_MOUSEUP
		|| keycode == ON_MOUSEDOWN)
	{
		ft_assign_coord(prm, prm->win_width / 2, prm->win_height / 2);
		if (keycode == ON_MOUSELEFTCLICK)
			mouse_leftclick(prm, x, y);
		else
		{
			if (prm->ctrl_zoom == 1)
			{
				ft_printf("zoom focus (x10^9) : (%d, %d)\n",
					(int)(prm->focus[0] * prm->prtfct),
					(int)(prm->focus[1] * prm->prtfct));
				ft_assign_cmplx(prm, prm->focus[0], prm->focus[1]);
			}
			if (keycode == ON_MOUSEUP)
				prm->zoom_now = prm->zoom_factor;
			else if (keycode == ON_MOUSEDOWN)
				prm->zoom_now = 1 / prm->zoom_factor;
		}
		ft_zoom(prm);
	}
	return (0);
}

int	mouse_leftclick(t_data *prm, int x, int y)
{
	ft_assign_coord(prm, x, y);
	prm->focus[0] = prm->cmplx[0];
	prm->focus[1] = prm->cmplx[1];
	ft_printf("focus click (x10^9) : (%d, %d)\n",
		(int)(prm->cmplx[0] * prm->prtfct),
		(int)(prm->cmplx[1] * prm->prtfct));
	prm->zoom_now = 1;
	return (0);
}

int	key_thsv(t_data *prm, int keycode)
{
	if (keycode == 65436 || keycode == 65430 || keycode == 65429)
	{
		if (prm->hm[0] <= 1)
			prm->hm[0] += (keycode == 65436 && prm->hm[0] > 0.01)
				* (-0.1) + (keycode == 65430) * (1 - prm->hm[0])
				+ (keycode == 65429) * 0.1
				+ (keycode == 65429 && prm->hm[0] == 1) * 0.9;
		else
			prm->hm[0] += (keycode == 65436) * (-1) + (keycode == 65430)
				* (1 - prm->hm[0]) + (keycode == 65429) * 1;
	}
	else if (keycode == 65433 || keycode == 65437 || keycode == 65431)
		prm->hm[2] += (keycode == 65433 && prm->hm[2] > 0.01) * (-0.1)
			+ (keycode == 65437) * (1 - prm->hm[2])
			+ (keycode == 65431 && prm->hm[2] < 1) * 0.1;
	else if (keycode == 65435 || keycode == 65432 || keycode == 65434)
		prm->hm[3] += (keycode == 65435 && prm->hm[3] > 0.01) * (-0.1)
			+ (keycode == 65432) * (1 - prm->hm[3])
			+ (keycode == 65434 && prm->hm[3] < 1) * 0.1;
	ft_printf("HSV : h_cf(%d), h_off(%d), s10(%d), v10(%d)\n", (int)prm->hm[0],
		(int)prm->hm[1], (int)(prm->hm[2] * 10), (int)(prm->hm[3] * 10));
	ft_image_update(prm);
	return (0);
}

int	key_thsv_2(t_data *prm, int keycode)
{
	prm->hm[1] += (-(keycode == 65453) + (keycode == 65451)) * 10;
	prm->hm[1] = ft_modulo(prm->hm[1], 360);
	if (prm->hm[1] < 0)
		prm->hm[1] = 360 + prm->hm[1];
	ft_printf("HSV : h_cf(%d), h_off(%d), s10(%d), v10(%d)\n", (int)prm->hm[0],
		(int)prm->hm[1], (int)(prm->hm[2] * 10), (int)(prm->hm[3] * 10));
	ft_image_update(prm);
	return (0);
}
