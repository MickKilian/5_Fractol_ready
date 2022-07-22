/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:02:56 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/07/19 03:54:15 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	ft_checkinput(int argc, char **argv, t_data *prm)
{
	if (argc > 1)
	{
		if (check_argv1(argc, argv, prm))
			return (1);
	}
	else
	{
		ft_listsets();
		return (1);
	}
	if (argc > 2)
		if (check_argv2(argc, argv, prm))
			return (ft_errorprompt());
	if (argc > 4)
		if (check_argv4(argc, argv, prm))
			return (ft_errorprompt());
	if (argc > 6)
		if (check_argv6(argc, argv, prm))
			return (ft_errorprompt());
	if (argc > 7)
		if (check_argv7(argc, argv, prm))
			return (ft_errorprompt());
	return (0);
}

int	check_argv1(int argc, char **argv, t_data *prm)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa(ft_atoi(argv[1]));
	(void)argc;
	while (i++ < prm->nb_handled_sets)
	{
		if ((!ft_strcmp(str, argv[1]) && ft_atoi(argv[1]) == i)
			|| !ft_strcmp(argv[1], prm->handled_sets[i - 1]))
		{
			prm->set = i;
			free (str);
			return (0);
		}
	}
	ft_listsets();
	free (str);
	return (1);
}

int	check_argv2(int argc, char **argv, t_data *prm)
{
	char	*str_2;
	char	*str_3;

	if (argc >= 4)
	{
		str_2 = ft_itoa(ft_atoi(argv[2]));
		str_3 = ft_itoa(ft_atoi(argv[3]));
		if (!ft_strcmp(str_2, argv[2])
			&& !ft_strcmp(str_3, argv[3]))
		{
			if (prm->set == 2)
			{
				prm->c[0] = (double)ft_atoi(argv[2]) / 100;
				prm->c[1] = (double)ft_atoi(argv[3]) / 100;
			}
			free (str_2);
			free (str_3);
			return (0);
		}
		free (str_2);
		free (str_3);
	}
	ft_printf("Please enter correct format (int) constant c (Re Im).\n");
	return (1);
}

int	check_argv4(int argc, char **argv, t_data *prm)
{
	char	*str_4;
	char	*str_5;

	if (argc >= 6)
	{
		str_4 = ft_itoa(ft_atoi(argv[4]));
		str_5 = ft_itoa(ft_atoi(argv[5]));
		if (!ft_strcmp(str_4, argv[4])
			&& !ft_strcmp(str_5, argv[5]))
		{
			prm->ctrl_zoom = 1;
			prm->focus[0] = (double)ft_atoi(argv[4]) / prm->prtfct;
			prm->focus[1] = (double)ft_atoi(argv[5]) / prm->prtfct;
			free (str_4);
			free (str_5);
			return (0);
		}
		free (str_4);
		free (str_5);
	}
	ft_printf("Please enter correct format (int) focus (Re Im).\n");
	return (1);
}

void	ft_listsets(void)
{
	ft_printf("Please enter a valid fractal set ->\n");
	ft_printf("1/ mandelbrot\n");
	ft_printf("2/ julia\n");
	ft_printf("3/ newton\n");
	ft_printf("4/ mandelbrot_mod\n");
	ft_printf("Followed by OPTIONAL PARAMETERS :\n");
	ft_printf("Constant (Re, Im), Zoom focus (Re, Im), Max Itr Incr\n");
}
