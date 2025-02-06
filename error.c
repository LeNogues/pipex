/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:25:14 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/02/05 16:07:56 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_message(int error_code)
{
	if (error_code == -1)
		write(1, "Could not create executable\n", 29);
	else if (error_code == -2)
		write(1, "Could not create full_path\n", 28);
	else if (error_code == -3)
		write(1, "Could not create pipe\n", 23);
}
