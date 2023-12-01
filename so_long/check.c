/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:48:43 by marboccu          #+#    #+#             */
/*   Updated: 2023/12/01 15:17:20 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_error(char *errormessage)
{
	ft_printf("\n###############################\n%s\n###############################\n\n", errormessage);
	exit(1);
}

void ft_checkerrors(t_data *matrix)
{
	if (matrix->coins_collected == 0)
		ft_error("NO DROPS, THE FLOOR IS TOO LAVA");
	if (matrix->player_count != 1)
		ft_error("WRONG NUMBER OF PLAYERS");
	if (matrix->exit_count != 1)
		ft_error("WRONG NUMBER OF EXITS");
}
