/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:14:50 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/07/19 03:56:49 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	ft_fractol(int argc, char **argv)
{
	t_data	prm;

	ft_bzero(&prm, sizeof(t_data));
	ft_init_data_0(&prm);
	if (!ft_checkinput(argc, argv, &prm)
		&& !ft_init_data_1(&prm)
		&& !ft_init_mlxwinimg(&prm))
	{
		mlx_hook(prm.win_ptr, 17, 1L << 17, &ft_exit, &prm);
		mlx_mouse_hook(prm.win_ptr, &mouse_hook, &prm);
		mlx_key_hook(prm.win_ptr, &key_hook, &prm);
		ft_image_update(&prm);
		mlx_loop(prm.mlx_ptr);
	}
	ft_exit(&prm);
	return (0);
}

int	ft_exit(t_data *prm)
{
	if (prm->mlx_ptr)
	{
		mlx_loop_end(prm->mlx_ptr);
		if (prm->img.img_ptr)
			mlx_destroy_image(prm->mlx_ptr, prm->img.img_ptr);
		if (prm->win_ptr)
			mlx_destroy_window(prm->mlx_ptr, prm->win_ptr);
		mlx_destroy_display(prm->mlx_ptr);
		free(prm->mlx_ptr);
	}
	exit(EXIT_SUCCESS);
	return (0);
}
