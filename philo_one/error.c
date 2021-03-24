/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:04:01 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/24 17:05:22 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_error(int index)
{
	if (index == MALLOC)
		ft_putstr_fd("Error: Malloc failed\n", STDERR_FILENO);
	exit(0);
}
