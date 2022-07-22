/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:02:56 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/07/19 03:54:33 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	check_argv6(int argc, char **argv, t_data *prm)
{
	char	*str;

	(void)argc;
	(void)prm;
	str = ft_itoa(ft_atoi(argv[6]));
	if (!ft_strcmp(str, argv[6]))
	{
		prm->mx_itr = ft_atoi(argv[6]);
		free (str);
		return (0);
	}
	ft_printf("Please enter correct format (int) for max_iterations.\n");
	free (str);
	return (1);
}

int	check_argv7(int argc, char **argv, t_data *prm)
{
	char	*str;

	(void)argc;
	(void)prm;
	str = ft_itoa(ft_atoi(argv[7]));
	if (!ft_strcmp(str, argv[7]))
	{
		prm->inc_itr = ft_atoi(argv[7]);
		free (str);
		return (0);
	}
	ft_printf("Please enter correct format (int) for iter increment.\n");
	free (str);
	return (1);
}

int	ft_errorprompt(void)
{
	write (1, "Error\n", 6);
	return (1);
}
