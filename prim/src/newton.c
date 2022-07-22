/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:13:12 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/07/19 03:57:20 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	ft_drawnewton(t_data *prm)
{
	t_clcnewton	var_newton;

	ft_bzero(&var_newton, sizeof(t_clcnewton));
	prm->max_newton = 0;
	prm->coord[1] = 0;
	while (prm->coord[1] < prm->img_height)
	{
		prm->coord[0] = 0;
		while (prm->coord[0] < prm->img_width)
		{
			ft_coord2cmplx(prm);
			var_newton.n = 0;
			prm->inset = !ft_isinnewtonset(prm, &var_newton);
			ft_assign_color(prm);
			ft_my_mlx_pixel_put(prm->img,
				prm->coord[0], prm->coord[1], prm->clr.val);
			prm->coord[0]++;
		}
		prm->coord[1]++;
	}
	return (0);
}

int	ft_isinnewtonset(t_data *prm, t_clcnewton *var_newton)
{
	var_newton->z[0] = prm->cmplx[0];
	var_newton->z[1] = prm->cmplx[1];
	while (var_newton->n++ < prm->mx_itr)
	{
		ft_function(var_newton);
		var_newton->z[0] -= var_newton->f1[0];
		var_newton->z[1] -= var_newton->f1[1];
		var_newton->i = 0;
		while (var_newton->i++ < 3)
		{
			if (ft_abs(var_newton->z[0]
					- prm->newton_roots[var_newton->i - 1][0]) < prm->tol
				&& ft_abs(var_newton->z[1]
				- prm->newton_roots[var_newton->i - 1][1]) < prm->tol)
			{
				prm->stp_itr = var_newton->n - 1;
				if (prm->stp_itr > prm->max_newton)
					prm->max_newton = prm->stp_itr;
				prm->newton_root = var_newton->i - 1;
				return (0);
			}
		}
	}
	return (1);
}

int	ft_function(t_clcnewton *var_newton)
{
	double	z[2];
	double	z1[2];
	double	z2[2];
	double	f[2];

	z[0] = var_newton->z[0];
	z[1] = var_newton->z[1];
	var_newton->f1[0] = z[0] * z [0] * z[0] - 3 * z[0] * z[1] * z[1] - 1;
	var_newton->f1[1] = -(z[1] * z[1] * z[1]) + 3 * z[0] * z[0] * z[1];
	var_newton->f2[0] = 3 * (z[0] * z[0] - z[1] * z[1]);
	var_newton->f2[1] = 6 * z[0] * z[1];
	z1[0] = var_newton->f1[0];
	z1[1] = var_newton->f1[1];
	z2[0] = var_newton->f2[0];
	z2[1] = var_newton->f2[1];
	f[0] = (z1[0] * z2[0] + z1[1] * z2[1]) / (z2[0] * z2[0] + z2[1] * z2[1]);
	f[1] = (z1[1] * z2[0] - z1[0] * z2[1]) / (z2[0] * z2[0] + z2[1] * z2[1]);
	var_newton->f1[0] = f[0];
	var_newton->f1[1] = f[1];
	return (0);
}
